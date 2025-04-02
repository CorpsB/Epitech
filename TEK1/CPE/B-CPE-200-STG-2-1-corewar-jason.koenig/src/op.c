/*
** EPITECH PROJECT, 2023
** OP COREWAR
** File description:
** OP.
*/

#include "../include/project.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive", &cor_live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &cor_ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", &cor_st},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &cor_add},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", &cor_sub},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3", &cor_and},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3", &cor_or},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3", &cor_xor},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &cor_zjump},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", &cor_ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", &cor_sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &cor_fork},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &cor_lld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", &cor_lldi},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &cor_lfork},
    {"aff", 1, {T_REG}, 16, 2, "aff", &cor_aff},
    {0, 0, {0}, 0, 0, 0}
};

int get_carry(int register_nb, champions_t *champion)
{
    int val = get_register(register_nb, champion);

    return (val == 0) ? 1 : 0;
}

void exec_function_selector(corewar_t *vm, champions_t *champion, char *action)
{
    corebag_t bag;
    int cmd_id = n_revbase(action, 16, 2);

    if (cmd_id < 1 || cmd_id > 16){
        champion->pc += 2;
        return;
    }
    if (champion->paid == op_tab[cmd_id - 1].nbr_cycles){
        champion->paid = PAID_START;
        create_bag(&bag, vm, champion, cmd_id);
        if (bag.arg1 != -1)
            op_tab[cmd_id - 1].func_ref(&bag);
        else
            champion->pc += 2;
    } else
        ++champion->paid;
}
