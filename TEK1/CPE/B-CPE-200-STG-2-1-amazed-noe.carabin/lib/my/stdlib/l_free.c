/*
** EPITECH PROJECT, 2023
** KJ_FREE_LIST
** File description:
** Free all content of a linked list.
*/

#include "../../../include/my.h"
void l_free(linked_list_t **list)
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
