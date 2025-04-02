/*
** EPITECH PROJECT, 2023
** KJ_FIND_IN_STR
** File description:
** Find a number into a string.
*/

#include "../../../include/my.h"
int s_search(char const *str, char c, char d)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= c && str[i] <= d)
            return (i);
    return (-1);
}
