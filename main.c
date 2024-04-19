#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#include "random_module.h"

#define LOCALEBASEDIR "."
#define TEXTDOMAIN "random"

#define _(STR) gettext(STR)
#define N_(STR) (STR)


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

    int res = 1;

    if(argc == 2) {
        res = atoi(argv[1]);
    }

    if(res <= 0) {
        fputs("Argument must be positive number\n", stderr);
        return 2;
    }

    throw_coin(res, callback_treat_coin, rc);
    if(res > 1) {
        print_res(rc);
    }

    return 0;
}
