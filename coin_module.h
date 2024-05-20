#ifndef COIN_MODULE_H
#define COIN_MODULE_H

struct result_coins;
struct result_coins *rc_init();
void print_res(struct result_coins *rc);

void throw_coin(int coin_toss_number, void (*callback)(int, void*), void *userdata);
void callback_treat_coin(int coinside, void* userdata);

#endif
