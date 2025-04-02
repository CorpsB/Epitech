/*
** EPITECH PROJECT, 2023
** MY_LIST_SIZE
** File description:
** A function that returns the number
** of elements on the list.
*/

#include "../../../include/shell.h"
int l_size(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}

int l_size_var(var_list_t *list)
{
    var_list_t *tmp = list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}

int l_pipe_size(pipe_data_t *list)
{
    pipe_data_t *tmp = list;
    int count = 0;

    for (; tmp != NULL; tmp = tmp->next)
        ++count;
    return (count);
}
