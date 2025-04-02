/*
** EPITECH PROJECT, 2023
** BAG
** File description:
** Project bag file.
*/

#include "../../include/project.h"

static int get_dir_size(int cmd)
{
    if (cmd == 10 || cmd == 14 || cmd == 3 || cmd == 11)
        return 2;
    return 4;
}

static int get_size_and_set_type(int *type, char *cb, corebag_t *bag)
{
    if (my_strncmp(cb, "01", 2) == 0){
        *type = REGISTER;
        return 1;
    }
    if (my_strncmp(cb, "10", 2) == 0){
        *type = DIRECT;
        return get_dir_size(bag->cmd_id);
    }
    if (my_strncmp(cb, "11", 2) == 0){
        *type = INDIRECT;
        return 2;
    }
    return 0;
}

static void store_arg_by_cb(int *stock, int *type, char *cb, corebag_t *bag)
{
    int size = get_size_and_set_type(type, cb, bag);

    if (size == 0){
        *stock = -1;
        return;
    }
    *stock = n_revbase(&bag->vm->memory[bag->champion->pc], 16, size * 2);
    if (size == 2 && *stock > 240)
        *stock -= 255;
    if (size == 4 && *stock > 65280)
        *stock -= 65535;
    bag->champion->pc += (size * 2);
}

void store_by_cb(corebag_t *bag, char *cb)
{
    store_arg_by_cb(&bag->arg1, &bag->arg1_type, cb, bag);
    store_arg_by_cb(&bag->arg2, &bag->arg2_type, &cb[2], bag);
    store_arg_by_cb(&bag->arg3, &bag->arg3_type, &cb[4], bag);
}

void store_specials(corebag_t *bag)
{
    int size = (bag->cmd_id == 1) ? 4 : 2;

    bag->champion->pc -= 2;
    bag->arg1 = n_revbase(&bag->vm->memory[bag->champion->pc], 16, size * 2);
    bag->arg1_type = DIRECT;
    if (bag->arg1 > 65280)
        bag->arg1 -= 65535;
    bag->arg2 = -1;
    bag->arg3 = -1;
    bag->champion->pc += (size * 2);
}

corebag_t *create_bag(corebag_t *bag, corewar_t *vm,
    champions_t *champion, int cmd)
{
    int cb_int;
    char *cb_char;

    bag->vm = vm;
    bag->champion = champion;
    bag->cmd_id = cmd;
    bag->head_pos = champion->pc;
    cb_int = n_revbase(&vm->memory[champion->pc + 2], 16, 2);
    champion->pc += 4;
    cb_char = n_base_zero(cb_int, 2);
    if (bag->cmd_id == 1 || bag->cmd_id == 9 || bag->cmd_id == 12 ||
    bag->cmd_id == 15)
        store_specials(bag);
    else
        store_by_cb(bag, cb_char);
    free(cb_char);
    return bag;
}
