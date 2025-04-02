/*
** EPITECH PROJECT, 2023
** MY_STRNCPY
** File description:
** Copy a given amout of characters of a string into an other one.
*/

#include "../../../include/my.h"
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
