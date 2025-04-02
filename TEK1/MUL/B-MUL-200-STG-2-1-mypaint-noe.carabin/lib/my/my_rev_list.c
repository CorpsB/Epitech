/*
** EPITECH PROJECT, 2023
** My Library (Epitech)
** File description:
** my_rev_list
*/

#include "../../includes/my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *p_tmp = NULL;
    linked_list_t *tmp = *begin;
    linked_list_t *n_tmp = NULL;

    while (tmp != NULL){
        n_tmp = tmp->next;
        tmp->next = p_tmp;
        p_tmp = tmp;
        tmp = n_tmp;
    }
    *begin = p_tmp;
}
