/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** st.c
*/

#include "../../include/project.h"

void cor_st(corebag_t *bag)
{
    int val = get_register(bag->arg1, bag->champion);

    if (bag->arg2_type == INDIRECT){
        write_arena(bag->head_pos + (bag->arg2 % IDX_MOD) * 2,
        val, bag, REG_SIZE * 2);
        return;
    }
    put_register(bag->arg2, val, bag->champion);
}
