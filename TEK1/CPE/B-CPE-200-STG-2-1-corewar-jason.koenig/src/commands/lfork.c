/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** lfork.c
*/

#include "../../include/project.h"

void cor_lfork(corebag_t *bag)
{
    int pc = bag->head_pos + (bag->arg1) * 2;

    l_add_champion(&bag->vm->champions);
    fork_champion(bag->champion, bag->vm->champions, bag->vm, pc);
}
