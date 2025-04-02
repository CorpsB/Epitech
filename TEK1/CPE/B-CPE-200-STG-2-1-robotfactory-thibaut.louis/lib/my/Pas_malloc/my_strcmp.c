/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** task06 my_strcmp.c
*/

#include <stdio.h>
#include "../../my.h"

int my_strcmp(const char *str1, const char *str2)
{
    int tmp = 0;
    int tmp2 = 0;

    if (str1[0] == '\0' && str2[0] == '\0')
        return 0;
    for (int i = 0; tmp == tmp2; i++){
        if (str1[i] == '\0' && str2[i] == '\0')
            return 0;
        tmp = tmp + str1[i];
        tmp2 = tmp2 + str2[i];
    }
    return (tmp - tmp2);
}

int my_strncmp(const char *str1, const char *str2, int n)
{
    int tmp = 0;
    int tmp2 = 0;

    if (str1[0] == '\0' && str2[0] == '\0')
        return 0;
    for (int i = 0; tmp == tmp2 && i < n; i++){
        if (str1[i] == '\0' && str2[i] == '\0')
            return 0;
        tmp = tmp + str1[i];
        tmp2 = tmp2 + str2[i];
    }
    return (tmp - tmp2);
}
