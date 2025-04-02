/*
** EPITECH PROJECT, 2023
** MY_PARAMS_TO_LIST
** File description:
** Tranform an array of strings into a linked list.
*/

#include "../../../include/my.h"
linked_list_t *l_convert_a(int ac, char **av)
{
    linked_list_t *list = NULL;

    for (int i = 0; i < ac; ++i)
        l_add(&list, av[i]);
    return (list);
}
