/*
** EPITECH PROJECT, 2023
** KJ_FREE_LIST
** File description:
** Free all content of a linked list.
*/

#include "../../../include/my.h"
#include "../../../include/hashtable.h"

void kj_free_list(linked_list_t **list)
{
    linked_list_t *target;
    linked_list_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->data);
        tmp = tmp->next;
        free(target);
    }
}

void kj_free_dlist(dlist **list)
{
    dlist *target;
    dlist *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->comment);
        tmp = tmp->next;
        free(target);
    }
}
