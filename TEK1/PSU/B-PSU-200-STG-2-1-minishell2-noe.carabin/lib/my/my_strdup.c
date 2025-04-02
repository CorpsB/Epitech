/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** copy and allocates memory.
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int taille(char *src)
{
    int taille = 0;

    for (; src[taille] != '\0'; taille ++) {
    }
    return (taille);
}

static char *my_strcpy_mais_2(char *src)
{
    int compteur = 0;
    char *dest = malloc(sizeof(char) * (taille(src) + 1));

    if (dest == NULL) {
        return (NULL);
    }
    for (; src[compteur] != '\0'; compteur++) {
        dest[compteur] = src[compteur];
    }
    dest[compteur] = '\0';
    return (dest);
}

char *my_strdup(char *src)
{
    return (my_strcpy_mais_2(src));
}
