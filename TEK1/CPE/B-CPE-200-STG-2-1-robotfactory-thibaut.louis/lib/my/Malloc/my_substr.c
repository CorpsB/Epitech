/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** my_substr.c
*/

#include "../../my.h"

char *my_substr(char *str1, int final, int begin)
{
    char *sortie = malloc(sizeof(char) * (final - begin + 1));

    for (int i = begin; i < final; i++)
        sortie[i - begin] = str1[i];
    sortie[final - begin] = '\0';
    return sortie;
}
