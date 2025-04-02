/*
** EPITECH PROJECT, 2024
** KJ_BOARD_SIZE
** File description:
** Returns the size of an array.
*/

#include "../../../include/base/my.h"

int a_size(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (; array[i] != NULL; ++i);
    return i;
}
