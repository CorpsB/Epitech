/*
** EPITECH PROJECT, 2023
** My Library (Epitech)
** File description:
** my_list_size
*/

#include "../../includes/my.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *tmp;
    int count;

    tmp = begin;
    while (tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}
