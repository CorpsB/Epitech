/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** sti.c
*/

#include "../../include/project.h"

void cor_sti(corebag_t *bag)
{
    int reg_content;
    int pos;
    char *val;

    if (bag->arg2_type == REGISTER)
        bag->arg2 = get_register(bag->arg2, bag->champion);
    if (bag->arg3_type == REGISTER)
        bag->arg3 = get_register(bag->arg3, bag->champion);
    reg_content = get_register(bag->arg1, bag->champion);
    val = get_hexa_base(reg_content, REG_SIZE * 2);
    pos = bag->head_pos + ((bag->arg2 + bag->arg3) % IDX_MOD) * 2;
    s_copy_from(bag->vm->memory, val, pos);
    for (int i = 0; i < REG_SIZE; ++i)
        bag->vm->mem_owner[pos / 2 + i] = bag->champion->map_id + 48;
    free(val);
}
