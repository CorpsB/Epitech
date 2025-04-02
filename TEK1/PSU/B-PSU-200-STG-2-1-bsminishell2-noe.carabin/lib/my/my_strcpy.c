/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** Exchange 2 string
*/

#include "../my.h"

/**
 * Prend en argument une deux string déjà malloc, et fait en sorte qu'elles
 * soient identiques.
*/
char *my_strcpy(char *dest, char const *src)
{
    int compteur = 0;

    for (; src[compteur] != '\0'; compteur++) {
        dest[compteur] = src[compteur];
    }
    return (dest);
}
