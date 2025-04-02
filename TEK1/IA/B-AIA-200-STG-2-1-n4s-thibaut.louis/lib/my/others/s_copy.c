/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** Copy a string into an other one.
*/

#include "../../../include/my.h"
char *s_copy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
