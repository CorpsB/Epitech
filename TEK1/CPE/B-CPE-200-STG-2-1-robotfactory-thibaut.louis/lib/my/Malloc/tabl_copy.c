/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** tabl_copy.c
*/

#include "../../my.h"

char **tabl_copy(char **tabl)
{
    char **result;
    int i = 0;

    result = malloc(sizeof(char *) * (tabl_size(tabl) + 1));
    for (; tabl[i] != NULL; i++){
        result[i] = my_strdup(tabl[i]);
    }
    result[i] = NULL;
    return (result);
}
