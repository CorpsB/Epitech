/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** table_len.c
*/

#include "../my.h"

/**
 * Cette fonction renvoie le nombre de ligne dans un tableau.
*/
int table_len(char **table)
{
    int i = 0;

    for (; table[i] != NULL; i++);
    return i;
}
