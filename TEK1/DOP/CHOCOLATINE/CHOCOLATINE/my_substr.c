/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_substr.c
*/

#include "my.h"

char *my_substr(char *str, int start, int end)
{
    int i = start;
    char *result = malloc(sizeof(char) * (end - start + 1));

    for (; start < end && str[start] != '\0'; start++)
        result[start - i] = str[start];
    result[start - i] = '\0';
    return result;
}
