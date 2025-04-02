/*
** EPITECH PROJECT, 2023
** LOAD
** File description:
** Project load file.
*/

#include "../../include/project.h"

// throw away things into 4th dimension using pointer shifting
void write_arena(int pc, int value, corebag_t *bag, int size)
{
    char *str_value = get_hexa_base(value, size);

    s_copy_from(bag->vm->memory, str_value, pc);
    for (int i = 0; i < REG_SIZE; ++i)
        bag->vm->mem_owner[pc / 2 + i] = bag->champion->map_id + 48;
    free(str_value);
}
