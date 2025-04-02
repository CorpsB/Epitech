/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** tools.c
*/

#include "include/my.h"

int get_nbr(char *str)
{
    int result = 0;
    int i = 0;

    for (; str[i] != '\0'; (i)++) {
        result = result * 10;
        result += (str[i] - 48);
    }
    return result;
}
