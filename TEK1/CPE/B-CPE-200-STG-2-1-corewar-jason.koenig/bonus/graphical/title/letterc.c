/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** letterc.c
*/

#include "../../../include/project.h"
#include "../../graphical.h"

char **letter_c(void)
{
    char **table = malloc(sizeof(char *) * 6);

    table[0] = my_strdup("XXXXX");
    table[1] = my_strdup("X    ");
    table[2] = my_strdup("X    ");
    table[3] = my_strdup("X    ");
    table[4] = my_strdup("XXXXX");
    table[5] = NULL;
    return table;
}
