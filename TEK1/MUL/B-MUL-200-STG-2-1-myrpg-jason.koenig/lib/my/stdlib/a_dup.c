/*
** EPITECH PROJECT, 2024
** KJ_BOARD_DUPLICATOR
** File description:
** Return the copy of an array.
*/

#include "../../../include/my.h"

char **a_dup(char **array)
{
    char **copy;
    int i = 0;

    copy = malloc(sizeof(char *) * (a_size(array) + 1));
    if (copy == NULL)
        return NULL;
    for (; array[i] != NULL; ++i)
        copy[i] = my_strdup(array[i]);
    copy[i] = NULL;
    return copy;
}
