/*
** EPITECH PROJECT, 2023
** My params to list
** File description:
** create a linked list
*/
#include <stdlib.h>
#include "include/mylist.h"

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list *list = NULL;
    int cpt = 0;

    for (; cpt < ac; cpt++) {
        my_put_in_list(&list, av[cpt]);
    }
    return (list);
}

int my_put_in_list(linked_list_t **list, char *av) 
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = av;
    element->next = *list;
    *list = element;
    return (0);
}
