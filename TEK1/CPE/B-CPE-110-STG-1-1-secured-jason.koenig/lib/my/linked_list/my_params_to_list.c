/*
** EPITECH PROJECT, 2023
** MY_PARAMS_TO_LIST
** File description:
** Tranform an array of strings into a linked list.
*/

#include "../../../include/my.h"
linked_list_t *my_params_to_list(int argc, char **argv)
{
    linked_list_t *l_chain = NULL;

    for (int i = 0; i < argc; ++i)
        kj_put_in_chain(&l_chain, argv[i]);
    return (l_chain);
}
