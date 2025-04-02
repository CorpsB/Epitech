/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** free_table.c
*/

#include "../my.h"

/**
 * Cette fonction prend un char ** et free son contenu.
*/
void free_table(char **table)
{
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
    return;
}
