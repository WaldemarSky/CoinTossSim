#include <stdio.h>
#include <locale.h>
#include <stdlib.h>                /* for atoi */

#include "coin_module.h"

#include <libintl.h>
#define _(STR) gettext(STR)
#define N_(STR) (STR)

#define LOCALEBASEDIR "./locale"
#define TEXTDOMAIN "tosscoin"


int main(int argc, char** argv)
{
    setlocale(LC_CTYPE, "");
    setlocale(LC_MESSAGES, "");
    bindtextdomain(TEXTDOMAIN, LOCALEBASEDIR);
    textdomain(TEXTDOMAIN);

    if(argc > 2) {
        fputs(_("Too many command line arguments\n"), stderr);
        return 1;
    }

    struct result_coins *rc = rc_init();

    int coin_toss_number = 1;

    if(argc == 2) {
        coin_toss_number = atoi(argv[1]);
        if(coin_toss_number <= 0) {
            fputs(_("Command line argument must be a positive number\n"), stderr);
            return 2;
        }
    }

    throw_coin(coin_toss_number, callback_treat_coin, rc);

    if(coin_toss_number > 1) {
        print_res(rc);
    }

    return 0;
}
