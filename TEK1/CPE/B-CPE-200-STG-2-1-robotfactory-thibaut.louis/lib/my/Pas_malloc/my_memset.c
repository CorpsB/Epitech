/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-robotfactory-thibaut.louis
** File description:
** my_memset.c
*/

#include "../../my.h"

char *my_memset(char *s, char c, int size)
{
    int i;

    i = 0;
    while (i < size) {
        s[i] = c;
        i++;
    }
    return (s);
}
