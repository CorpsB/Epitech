/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** aff.c
*/

#include "../../include/project.h"

void cor_aff(corebag_t *bag)
{
    my_putchar(get_register(bag->arg1, bag->champion) % 256, 1);
    my_putchar('\n', 1);
}
