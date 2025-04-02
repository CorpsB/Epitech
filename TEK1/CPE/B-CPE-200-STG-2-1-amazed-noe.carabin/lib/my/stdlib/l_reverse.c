/*
** EPITECH PROJECT, 2023
** MY_REV_LIST
** File description:
** Reverse a linked list using pointers.
*/

#include "../../../include/my.h"
void l_reverse(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}
