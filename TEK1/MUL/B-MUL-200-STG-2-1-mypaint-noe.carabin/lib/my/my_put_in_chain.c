/*
** EPITECH PROJECT, 2023
** My Library (Epitech)
** File description:
** my_put_in_chain
*/

#include "../../includes/my.h"

void my_put_in_chain(linked_list_t **list, char *data)
{
    linked_list_t *n_chain;

    n_chain = malloc(sizeof(struct linked_list));
    n_chain->next = *list;
    n_chain->data = my_strdup(data);
    *list = n_chain;
}
