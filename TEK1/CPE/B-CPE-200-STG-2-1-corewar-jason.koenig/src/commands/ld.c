/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** ld.c
*/

#include "../../include/project.h"

void cor_ld(corebag_t *bag)
{
    get_indirect(REG_SIZE, bag);
    put_register(bag->arg2, bag->arg1, bag->champion);
    bag->champion->carry = get_carry(bag->arg2, bag->champion);
}
