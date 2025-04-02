/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** add.c
*/

#include "my.h"

static int disp_add_msg(char *name, char *type, int *nbr)
{
    my_putstr(type);
    my_putstr(" n°");
    my_putnbr((*nbr) - 1);
    my_putstr(" - \"");
    my_putstr(name);
    my_putstr("\" added.\n");
}

static int add_in_list(linked_list_t **liste, char *name, char *type, int *nbr)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->name = my_strdup(name);
    element->type = my_strdup(type);
    element->nbr = *nbr;
    *(nbr) += 1;
    element->next = *liste;
    *liste = element;
    disp_add_msg(name, type, nbr);
    return (0);
}

int switch_type(list_and_nbr *liste, char *type, char *name)
{
    if (my_strcompare(type, "ACTUATOR") == 1) {
        return (add_in_list(&(liste->list), name, "ACTUATOR", &(liste->nbr)));
    }
    if (my_strcompare(type, "DEVICE") == 1) {
        return (add_in_list(&(liste->list), name, "DEVICE", &(liste->nbr)));
    }
    if (my_strcompare(type, "PROCESSOR") == 1) {
        return add_in_list(&(liste->list), name, "PROCESSOR", &(liste->nbr));
    }
    if (my_strcompare(type, "SENSOR") == 1) {
        return add_in_list(&(liste->list), name, "SENSOR", &(liste->nbr));
    }
    if (my_strcompare(type, "WIRE") == 1) {
        return add_in_list(&(liste->list), name, "WIRE", &(liste->nbr));
    }
    return 84;
}

int add(void *data, char **args)
{
    int error = 0;
    int nbr = get_table_size(args);

    if (nbr % 2 != 0 || nbr == 0) {
        return 84;
    }
    for (int i = 0; i < nbr || error == 84; i += 2) {
        error = switch_type(data, args[i], args[i + 1]);
        if (error == 84)
            break;
    }
    return error;
}
