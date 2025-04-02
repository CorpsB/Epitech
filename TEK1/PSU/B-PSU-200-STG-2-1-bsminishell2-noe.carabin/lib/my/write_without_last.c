/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** write_without_last.c
*/

#include "../my.h"

/**
 * Cette focntion renvoie une string sans son dernier caractère.
*/
char *write_withoutlast(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[i + 1] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    free(str);
    return result;
}
