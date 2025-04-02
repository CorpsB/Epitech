/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** my_strcat
*/

#include "../../includes/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int length1 = my_strlen(dest);
    int length2 = my_strlen(src);
    char *str;

    str = malloc((sizeof(char) * (length1 + length2) + 1));
    for (; i < dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (int j = 0; src[j] != '\0'; i++){
        str[i] = src[j];
        j++;
    }
    str[i] = '\0';
    return str;
}
