/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str);
    char *new_str = malloc((len + 1) * sizeof(char));

    if (str == NULL) {
        return NULL;
    }
    for (int i = 0; i <= len; i++) {
        new_str[i] = str[i];
    }
    return new_str;
}
