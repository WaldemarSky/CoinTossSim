#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "coin_module.h"

#define EAGLE 0
#define TAIL 1

static const char* arr_coinsides[] = {
    "EAGLE",
    "TAIL"
};


struct result_coins {

    int egtails_number[2];

    int max_seria;

    int cur_seria; 
    int cur_seria_size;
};

struct result_coins *rc_init()
{
    struct result_coins *res = calloc(1, sizeof(struct result_coins));
    res->max_seria = 1;

    return res;
}


void callback_treat_coin(int coinside, void* userdata)
{
    struct result_coins *rc =  userdata;
    ++rc->egtails_number[coinside];

    if(rc->cur_seria == coinside) {
        ++rc->cur_seria_size;
        if(rc->cur_seria_size > rc->max_seria) {
            rc->max_seria = rc->cur_seria_size;
        }
    } else {
        rc->cur_seria = coinside;
        rc->cur_seria_size = 1;
    }
}

void throw_coin(int coin_toss_number, void (*callback)(int, void*), void *userdata)
{
    srand(time(NULL));

    for(int i = coin_toss_number; i > 0; --i) {
        int coinside = (int) (2.0*rand() / (RAND_MAX + 1.0));
        if(coin_toss_number <= 50) {
            puts(arr_coinsides[coinside]);
        }
        callback(coinside, userdata);
    }

}


void print_res(struct result_coins *rc)
{
    printf("Total Eagles: %d, Tails: %d, Maximum seria: %d\n",
           rc->egtails_number[0],
           rc->egtails_number[1],
           rc->max_seria);
}
