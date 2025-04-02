/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** Exchange 2 string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int compteur = 0;

    for (; src[compteur] != '\0'; compteur++) {
        dest[compteur] = src[compteur];
    }
    dest[compteur] = '\0';
    return (dest);
}
