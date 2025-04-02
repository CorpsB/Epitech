/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** str_str.c
*/

#include "../my.h"

/**
 * Cette fonction prend deux chaines de caractères et les concatènent (dans
 * l'ordre).
*/
char *my_strstr(char *src, char *se)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + my_strlen(se) + 1));
    int index = 0;
    bool first = false;

    for (int i = 0; src[i] != '\0'; i++) {
        result[index] = src[i];
        index++;
    }
    for (int i = 0; se[i] != '\0'; i++) {
        result[index] = se[i];
        index++;
    }
    result[index] = '\0';
    return result;
}
