/*
** EPITECH PROJECT, 2023
** MY_LIST_SIZE
** File description:
** A function that returns the number
** of elements on the list.
*/

#include "../../../include/my.h"
int l_size(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}
