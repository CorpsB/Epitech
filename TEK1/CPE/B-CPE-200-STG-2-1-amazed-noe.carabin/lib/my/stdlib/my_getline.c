/*
** EPITECH PROJECT, 2024
** MY_GETLINE
** File description:
** Yes.
*/

#include "../../../include/my.h"

char *my_getline(char *str, int *i)
{
    char *result;
    int j = *i;

    for (; str[*i] != '\n' && str[*i] != '\0'; ++(*i));
    result = my_substr(str, j, *i);
    ++(*i);
    return result;
}
