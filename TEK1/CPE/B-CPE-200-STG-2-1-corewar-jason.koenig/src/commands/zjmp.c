/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** zjmp.c
*/

#include "../../include/project.h"

void cor_zjump(corebag_t *bag)
{
    if (bag->champion->carry == 1){
        bag->champion->pc -= 6;
        if (bag->arg1 < 0)
            bag->champion->pc -= 2;
        bag->champion->pc += ((bag->arg1 * 2) % IDX_MOD);
    }
}
