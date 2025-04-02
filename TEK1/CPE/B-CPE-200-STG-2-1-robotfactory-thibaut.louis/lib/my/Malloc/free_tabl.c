/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** free_tabl.c
*/

#include "../../my.h"

void free_tabl(char **result)
{
    if (result == NULL)
        return;
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);
}
