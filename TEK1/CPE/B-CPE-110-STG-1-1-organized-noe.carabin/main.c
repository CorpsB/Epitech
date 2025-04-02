/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** main.c
*/

#include "my.h"
#include "libshell/shell.h"
#include <stdbool.h>
#include <stddef.h>

int del_list(linked_list_t **list)
{
    linked_list_t *temp;

    while (*list != NULL) {
        free((*list)->name);
        free((*list)->type);
        temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    return 0;
}

int main(int ac, char **av)
{
    list_and_nbr linked_list;
    int error = 0;

    linked_list.list = NULL;
    linked_list.nbr = 0;
    error = workshop_shell(&linked_list);
    del_list(&linked_list.list);
    return error;
}
