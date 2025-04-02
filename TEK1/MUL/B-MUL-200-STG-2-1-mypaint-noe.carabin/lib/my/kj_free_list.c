/*
** EPITECH PROJECT, 2023
** KJ_FREE_LIST
** File description:
** Free a linked_list.
*/

#include "../../includes/my.h"

void kj_free_list(linked_list_t *list)
{
    linked_list_t *target;

    while (list != NULL){
        target = list;
        free(list->data);
        list = list->next;
        free(target);
    }
}
