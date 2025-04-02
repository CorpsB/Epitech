/*
** EPITECH PROJECT, 2023
** flag_n.C
** File description:
** flag_n.c
*/

#include "../my.h"
#include <unistd.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int flag_n(char *str)
{
    char chaine[10];

    if (str != NULL) {
        my_strncpy(chaine, str, sizeof(chaine) - 1);
        chaine[sizeof(chaine) - 1] = '\0';
    }
    return 0;
}
