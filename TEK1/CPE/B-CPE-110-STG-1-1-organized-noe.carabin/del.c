/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-noe.carabin
** File description:
** del.c
*/

#include "my.h"

static int send_message(char *name, char *type, int nbr)
{
    my_putstr(type);
    my_putstr(" n°");
    my_putnbr(nbr);
    my_putstr(" - \"");
    my_putstr(name);
    my_putstr("\" deleted.\n");
}

static int arg_in_nbr(char *args)
{
    int size = my_strlen(args);
    int result = 0;
    int mult = 1;

    for (int i = size; i > 0; i--) {
        result = (args[i - 1] - 48) * mult;
        mult *= 10;
    }
    return result;
}

static int del_node(linked_list_t *prv)
{
    free(prv->name);
    free(prv->type);
    free(prv);
    return 0;
}

void delete_first(linked_list_t *tmp, linked_list_t *prv, linked_list_t **list)
{
    send_message(tmp->name, tmp->type, tmp->nbr);
    prv = tmp;
    tmp = tmp->next;
    del_node(prv);
    *list = tmp;
}

int del_in_list(linked_list_t **list, int nbr)
{
    linked_list_t *prv = NULL;
    linked_list_t *tmp = *list;

    if (tmp->nbr == nbr) {
        delete_first(tmp, prv, list);
        return 0;
    }
    while (tmp != NULL) {
        if (tmp->nbr != nbr) {
            prv = tmp;
            tmp = tmp->next;
            continue;
        }
        send_message(tmp->name, tmp->type, tmp->nbr);
        prv->next = tmp->next;
        return del_node(tmp);
    }
    return 84;
};

int del(void *data, char **args)
{
    int size = get_table_size(args);
    list_and_nbr *list = data;
    int nbr;
    int error = 0;

    if (size == 0) {
        return 84;
    }
    for (int i = 0; i < size || error == 84; i++) {
        nbr = arg_in_nbr(args[i]);
        error = del_in_list(&(list->list), nbr);
        if (error != 0) {
            break;
        }
    }
    return error;
}
