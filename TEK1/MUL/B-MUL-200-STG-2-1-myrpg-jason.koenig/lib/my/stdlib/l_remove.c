/*
** EPITECH PROJECT, 2023
** DELETE_IN_LIST
** File description:
** Delete a node from a linked_list.
*/

#include "../../../include/my.h"
static void delete_arg(linked_list_t **begin, linked_list_t *tmp,
    linked_list_t *prev)
{
    if (prev == NULL)
        *begin = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void l_remove(linked_list_t **list, void const *ref,
    int (*cmp_fct)())
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (tmp != NULL){
        if (cmp_fct(tmp->data, ref) == 0){
            next = tmp->next;
            delete_arg(list, tmp, prev);
            tmp = next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}
