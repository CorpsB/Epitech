/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** unsetenv.c
*/

#include "my.h"

int remove_env(linked_t **list, char **name)
{
    linked_t *tmp = *list;
    int i;

    if (table_len(name) == 1) {
        my_error("unsetenv: Too few arguments.\n");
        return 1;
    }
    i = search_from_list(*list, name[1]);
    if (i == -1)
        return 0;
    del_in_list(list, i);
    return 0;
}
