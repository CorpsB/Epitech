/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-thibaut.louis
** File description:
** clean_array.c
*/

#include "../../my.h"

void clean_array(char ***tabl)
{
    char *tmp = NULL;

    for (int i = 0; (*tabl)[i] != NULL; i++) {
        tmp = clean_str((*tabl)[i], ' ', '\t');
        free((*tabl)[i]);
        (*tabl)[i] = my_strdup(tmp);
        free(tmp);
    }
}
