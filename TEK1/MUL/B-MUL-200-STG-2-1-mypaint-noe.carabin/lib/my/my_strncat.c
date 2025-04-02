/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** my_strncat
*/

#include "../../includes/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int length1 = my_strlen(dest);
    int length2 = my_strlen(src);
    char *str;

    str = malloc((sizeof(char) * (length1 + nb) + 1));
    for (; i < dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (int j = 0; j < nb; i++){
        str[i] = src[j];
        j++;
    }
    str[i] = '\0';
    return str;
}
