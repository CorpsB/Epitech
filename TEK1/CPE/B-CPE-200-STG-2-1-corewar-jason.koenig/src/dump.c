/*
** EPITECH PROJECT, 2024
** DUMP MEMORY
** File description:
** Display the content of the memory.
*/

#include "../include/project.h"

void dump_memory(corewar_t *vm)
{
    int cpt = 0;

    for (int i = 0; vm->memory[i] != '\0'; ++i){
        my_putchar(vm->memory[i], 1);
        if (cpt % 2 != 0 && cpt != 63)
            my_putchar(' ', 1);
        if (cpt == 63){
            my_putchar('\n', 1);
            cpt = 0;
        } else {
            ++cpt;
        }
    }
    if (cpt != 0)
        my_putchar('\n', 1);
}
