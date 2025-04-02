/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int nbr, int start)
{
    int i = 0;

    for (; i < nbr && src[start] != '\0'; start++) {
        dest[i] = src[start];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
