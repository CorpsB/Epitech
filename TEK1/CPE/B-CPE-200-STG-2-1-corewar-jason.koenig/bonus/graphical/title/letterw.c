/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** letterw.c
*/

#include "../../../include/project.h"
#include "../../graphical.h"

char **letter_w(void)
{
    char **table = malloc(sizeof(char *) * 6);

    table[0] = my_strdup("X   X");
    table[1] = my_strdup("X   X");
    table[2] = my_strdup("X X X");
    table[3] = my_strdup("X X X");
    table[4] = my_strdup(" X X ");
    table[5] = NULL;
    return table;
}
