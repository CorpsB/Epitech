/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-noe.carabin
** File description:
** disp.c
*/

#include "my.h"

int disp(void *data, char **args)
{
    list_and_nbr *something = data;
    linked_list_t *tmp;
    linked_list_t *list = something->list;

    if (get_table_size(args) != 0)
        return 84;
    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->type);
        my_putstr(" n°");
        my_putnbr(tmp->nbr);
        my_putstr(" - \"");
        my_putstr(tmp->name);
        my_putchar('\"');
        my_putchar('\n');
        tmp = tmp->next;
    }
    return 0;
}
