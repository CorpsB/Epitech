/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** aff_tabl.c
*/

#include <stdio.h>
#include "../../my.h"

void aff_tabl(char **result)
{
    for (int i = 0; result[i] != NULL; i++) {
        my_putstr(result[i]);
        my_putchar('\n');
    }
}
