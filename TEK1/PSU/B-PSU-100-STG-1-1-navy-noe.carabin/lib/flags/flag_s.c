/*
** EPITECH PROJECT, 2023
** flag_s.c
** File description:
** écrit des strings
*/

#include "../my.h"
#include <stdio.h>
#include <stdarg.h>

int flag_s(char *c)
{
    if (c != NULL)
        my_putstr(c);
    else
        return 84;
    return 0;
}
