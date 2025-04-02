/*
** EPITECH PROJECT, 2023
** KJ_PUT_IN_CHAIN
** File description:
** Put a string into a linked list.
*/

#include "../../../include/my.h"
void kj_put_in_chain(linked_list_t **l_chain, void *arg)
{
    linked_list_t *s_l_chain = malloc(sizeof(struct linked_list));

    s_l_chain->data = my_strdup(arg);
    s_l_chain->next = *l_chain;
    *l_chain = s_l_chain;
}
