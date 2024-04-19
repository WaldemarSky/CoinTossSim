#ifndef RANDOM_MODULE_SENTRY
#define RANDOM_MODULE_SENTRY

struct result_coins;
struct result_coins *rc_init();
void print_res(struct result_coins *rc);

void throw_coin(int amount_of_times, void (*callback)(int, void*), void *userdata);
void callback_treat_coin(int coinside, void* userdata);

#endif
