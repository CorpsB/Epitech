/*
** EPITECH PROJECT, 2024
** MY_GETLINE
** File description:
** Yes.
*/

#include "../../../include/my.h"

char *my_getline(char *str, int *i, char sep)
{
    char *result;
    int j = *i;

    for (; str[*i] != sep && str[*i] != '\0'; ++(*i));
    if (str[j] == ' ')
        ++j;
    if (str[*i - 1] == ' ')
        result = my_substr(str, j, *i - 1);
    else
        result = my_substr(str, j, *i);
    if (str[*i] != '\0')
        ++(*i);
    return result;
}
