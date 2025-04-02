/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-noe.carabin
** File description:
** sort.c
*/

#include "my.h"

static void swap_chainlist_id(linked_list_t *stop, linked_list_t *current)
{
    char *name;
    char *type;
    int id;

    if (stop->nbr > current->nbr) {
        id = stop->nbr;
        stop->nbr = current->nbr;
        current->nbr = id;
        name = stop->name;
        stop->name = current->name;
        current->name = name;
        type = stop->type;
        stop->type = current->type;
        current->type = type;
    }
    return;
}

static int sort_id(void *data)
{
    list_and_nbr **give = data;
    linked_list_t *current = (*give)->list;

    for (linked_list_t *stop = current; stop != NULL; stop = stop->next) {
        for (current = stop->next; current != NULL; current = current->next) {
            swap_chainlist_id(stop, current);
        }
    }
    return 0;
}

static void swap_chainlist_type(linked_list_t *stop, linked_list_t *current)
{
    char *name;
    char *type;
    int id;

    if (stop->type[0] > current->type[0]) {
        id = stop->nbr;
        stop->nbr = current->nbr;
        current->nbr = id;
        name = stop->name;
        stop->name = current->name;
        current->name = name;
        type = stop->type;
        stop->type = current->type;
        current->type = type;
    }
    return;
}

static int sort_type(void *data)
{
    list_and_nbr **give = data;
    linked_list_t *current = (*give)->list;

    for (linked_list_t *stop = current; stop != NULL; stop = stop->next) {
        for (current = stop->next; current != NULL; current = current->next) {
            swap_chainlist_type(stop, current);
        }
    }
    return 0;
}

static void swap_chainlist_name(linked_list_t *stop, linked_list_t *current)
{
    char *name;
    char *type;
    int id;

    if (my_strcmp(stop->name, current->name) > 0) {
        id = stop->nbr;
        stop->nbr = current->nbr;
        current->nbr = id;
        name = stop->name;
        stop->name = current->name;
        current->name = name;
        type = stop->type;
        stop->type = current->type;
        current->type = type;
    }
    return;
}

static int sort_name(void *data)
{
    list_and_nbr **give = data;
    linked_list_t *current = (*give)->list;

    for (linked_list_t *stop = current; stop != NULL; stop = stop->next) {
        for (current = stop->next; current != NULL; current = current->next) {
            swap_chainlist_name(stop, current);
        }
    }
    return 0;
}

static int switch_sort(void *data, char **args)
{
    if (my_strcompare(args[0], "TYPE") == 1) {
        return (sort_type(&data));
    }
    if (my_strcompare(args[0], "NAME") == 1) {
        return (sort_name(&data));
    }
    if (my_strcompare(args[0], "ID") == 1) {
        return (sort_id(&data));
    }
    return 84;
}

int sort(void *data, char **args)
{
    int nbr = get_table_size(args);

    if (nbr == 1) {
        return (switch_sort(data, args));
    }
    if (nbr == 2 && my_strcompare(args[1], "-r")) {
        return (switch_revsort(data, args));
    }
    return 84;
}
