/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** show_table.c
*/

#include "../my.h"

/**
 * Cette fonction affiche dans le terminal le contenue d'un char **
*/
void show_table(char **table)
{
    for (int i = 0; table[i] != NULL; i++)
        my_putstr(table[i]);
    return;
}
