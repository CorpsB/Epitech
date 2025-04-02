/*
** EPITECH PROJECT, 2023
** MY_LIST_SIZE
** File description:
** MY_LIST_SIZE
*/

#include <stdlib.h>
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int cpt = 0;
    linked_list_t *tmp = begin;

    for (;tmp != NULL; cpt++) {
        tmp = tmp->next;
    }
    return (cpt);
}
