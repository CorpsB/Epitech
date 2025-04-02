/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** my_strncpy
*/

#include "../../includes/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
