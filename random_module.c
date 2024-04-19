#include <time.h>
#include <stdlib.h>

#include "random_module.h"

#define EAGLE 0
#define TAIL 1

static const char* arr_coinsides[] = {
    "EAGLE",
    "TAIL"
};


struct result_coins {

    int arr_egtails[2];

    int max_seria;

    int cur_seria; 
    int cur_seria_size;
};

struct result_coins *rc_init()
{
   return calloc(1, sizeof(struct result_coins));
}

void callback_treat_coin(int coinside, void* userdata)
{
    struct result_coins *rc =  userdata;
    ++rc->arr_egtails[coinside];

    if(rc->cur_seria == coinside) {
        ++rc->cur_seria_size;
    } else {
        rc->cur_seria = coinside;
        rc->cur_seria_size = 1;
    }

    if(rc->cur_seria_size > rc->max_seria) {
        rc->max_seria = rc->cur_seria_size;
    }
}

void print_res(struct result_coins *rc)
{
    printf("Total Eagles: %d, Tails: %d, Maximum seria: %d\n",
           rc->arr_egtails[0],
           rc->arr_egtails[1],
           rc->max_seria);
}


void throw_coin(int amount_of_times, void (*callback)(int, void*), void *userdata) 
{
    srand(time(NULL));

    for(int i = amount_of_times; i > 0; --i) {
        int coinside = (int) (2.0*rand() / (RAND_MAX + 1.0));
        if(amount_of_times <= 50) {
            puts(arr_coinsides[coinside]);
        }
        callback(coinside, userdata);
    }

}
