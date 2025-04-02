/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../../include/project.h"

static void get_indirect_arg(corebag_t *bag, int size, int *stock)
{
    if (bag->cmd_id > 12 && bag->cmd_id < 16){
        *stock = n_revbase(&bag->vm->memory[bag->head_pos + (*stock * 2)],
        16, size * 2);
        return;
    }
    *stock = n_revbase(&bag->vm->memory[bag->head_pos +
    (*stock * 2) % IDX_MOD], 16, size * 2);
}

void get_indirect(int size, corebag_t *bag)
{
    if (bag->arg1 != -1 && bag->arg1_type == INDIRECT)
        get_indirect_arg(bag, size, &bag->arg1);
    if (bag->arg2 != -1 && bag->arg2_type == INDIRECT)
        get_indirect_arg(bag, size, &bag->arg2);
    if (bag->arg3 != -1 && bag->arg3_type == INDIRECT)
        get_indirect_arg(bag, size, &bag->arg3);
}
