/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** ldi.c
*/

#include "../../include/project.h"

void cor_ldi(corebag_t *bag)
{
    int val;

    if (bag->arg1_type == REGISTER)
        bag->arg1 = get_register(bag->arg1, bag->champion);
    if (bag->arg2_type == REGISTER)
        bag->arg2 = get_register(bag->arg2, bag->champion);
    get_indirect(IND_SIZE, bag);
    val = n_revbase(&bag->vm->memory[bag->head_pos +
    ((bag->arg1 + bag->arg2) % IDX_MOD) * 2], 16, REG_SIZE * 2);
    put_register(bag->arg3, val, bag->champion);
    bag->champion->carry = get_carry(bag->arg3, bag->champion);
}
