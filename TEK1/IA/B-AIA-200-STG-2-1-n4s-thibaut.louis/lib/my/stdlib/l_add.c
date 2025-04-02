/*
** EPITECH PROJECT, 2023
** KJ_PUT_IN_CHAIN
** File description:
** Put a string into a linked list.
*/

#include "../../../include/my.h"
void l_add(linked_list_t **list, void *arg)
{
    linked_list_t *s_list = malloc(sizeof(struct linked_list));

    s_list->data = arg;
    s_list->next = *list;
    *list = s_list;
}
