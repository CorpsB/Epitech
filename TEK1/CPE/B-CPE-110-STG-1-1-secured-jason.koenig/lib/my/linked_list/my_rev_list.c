/*
** EPITECH PROJECT, 2023
** MY_REV_LIST
** File description:
** Reverse a linked list using pointers.
*/

#include "../../../include/my.h"
void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list = *begin;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (list != NULL){
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }
    *begin = prev;
}
