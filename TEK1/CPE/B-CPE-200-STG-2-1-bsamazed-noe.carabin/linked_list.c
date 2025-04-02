/*
** EPITECH PROJECT, 2023
** new_folder
** File description:
** linked_list.c
*/

#include "my.h"

void my_show_list(linked_t *list)
{
    linked_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_put_nbr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

/*void my_show_revlist(linked_t *tmp)
{
    if (tmp == NULL) {
        return;
    }
    my_show_revlist(tmp->next);
    my_putstr(tmp->data);
    my_putchar('\n');
}

int my_list_size(linked_t *begin)
{
    int cpt = 0;
    linked_t *tmp = begin;

    for (; tmp != NULL; cpt++) {
        tmp = tmp->next;
    }
    return (cpt);
    }*/
int my_put_in_list(linked_t **list, int nbr)
{
    linked_t *element;

    element = malloc(sizeof(*element));
    element->data = nbr;
    element->next = *list;
    *list = element;
    return (0);
}

/*static int del_node(linked_t *prv)
{
    free(prv->data);
    free(prv);
    return 0;
}

static void delete_first(linked_t *tmp, linked_t *prv, linked_t **list)
{
    prv = tmp;
    tmp = tmp->next;
    del_node(prv);
    *list = tmp;
}

int del_in_list(linked_t **list, int id)
{
    linked_t *prv = NULL;
    linked_t *tmp = *list;

    if (tmp->data == id) {
        delete_first(tmp, prv, list);
        return 0;
    }
    while (tmp != NULL) {
        if (tmp->data != id) {
            prv = tmp;
            tmp = tmp->next;
            continue;
        }
        prv->next = tmp->next;
        return del_node(tmp);
    }
    return 84;
    }*/
