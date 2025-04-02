/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** get_nbr.c
*/

#include "my.h"

int get_nbr(char *str)
{
    int result = 0;

    if (str == NULL)
        return 0;
    result = str[0] - 48;
    for (int i = 1; str[i] != '\0'; i++) {
        result *= 10;
        result += (str[i] - 48);
    }
    return result;
}
