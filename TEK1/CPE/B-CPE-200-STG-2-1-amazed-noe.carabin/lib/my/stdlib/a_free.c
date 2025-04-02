/*
** EPITECH PROJECT, 2024
** KJ_FREE_BOARD
** File description:
** Free an array.
*/

#include "../../../include/my.h"

void a_free(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
}
