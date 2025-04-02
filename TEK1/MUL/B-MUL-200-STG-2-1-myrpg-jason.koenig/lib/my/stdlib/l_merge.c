/*
** EPITECH PROJECT, 2023
** MY_CONCAT_LIST
** File description:
** Concat two linked list.
*/

#include "../../../include/my.h"
void l_merge(linked_list_t **list_1, linked_list_t **list_2)
{
    linked_list_t *tmp = *list_1;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *list_2;
}
