/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** free.c
*/

#include "my.h"

void free_infos(linked_t **list)
{
    linked_t *tmp = *list;
    linked_t *prev;

    if (*list == NULL)
        return;
    for (; tmp != NULL;) {
        if (tmp->value != NULL)
            free(tmp->value);
        if (tmp->name != NULL)
            free(tmp->name);
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
    *list = NULL;
}

void free_path(path_t **list)
{
    path_t *tmp = *list;
    path_t *prev;

    if (*list == NULL)
        return;
    for (; tmp != NULL;) {
        free(tmp->path);
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
    free(tmp);
}

void free_table(char **table)
{
    if (table == NULL)
        return;
    for (int i = 0; table[i] != NULL; i++) {
        free(table[i]);
    }
    free(table);
}
