/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** live.c
*/

#include "../../include/project.h"

void cor_live(corebag_t *bag)
{
    my_printf("The player %d(%s) is alive.\n",
    bag->arg1, bag->champion->data.prog_name);
    bag->champion->cycle_life = 0;
    bag->vm->last_live = bag->champion;
    ++bag->vm->nb_live;
}
