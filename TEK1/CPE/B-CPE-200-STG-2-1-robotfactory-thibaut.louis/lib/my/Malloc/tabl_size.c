/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** tabl_size.c
*/

#include <stdio.h>
#include "../../my.h"

int tabl_size(char **result)
{
    int tmp = 0;

    for (int i = 0; result[i] != NULL; i++) {
        tmp++;
    }
    return tmp;
}
