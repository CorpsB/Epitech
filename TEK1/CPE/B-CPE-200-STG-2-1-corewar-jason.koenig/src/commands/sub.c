/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** sub.c
*/

#include "../../include/project.h"

void cor_sub(corebag_t *bag)
{
    int value1 = get_register(bag->arg1, bag->champion);
    int value2 = get_register(bag->arg2, bag->champion);

    put_register(bag->arg3, value1 - value2, bag->champion);
    bag->champion->carry = get_carry(bag->arg3, bag->champion);
}
