/*
** EPITECH PROJECT, 2023
** My Library (Epitech)
** File description:
** my_strdup
*/

#include "../../includes/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int length = my_strlen(src);
    int i = 0;

    str = malloc((sizeof(char) * length) + 1);
    for (; i < length; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
