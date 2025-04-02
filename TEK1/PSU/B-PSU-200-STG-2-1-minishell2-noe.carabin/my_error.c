/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_error.c
*/

#include "my.h"
#include <stdarg.h>

int my_error(char const *str)
{
    char tmp;

    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        tmp = str[i];
        write(2, &tmp, 1);
    }
}

int message(int exit_code, int exit_in, int nbr, ...)
{
    va_list list;

    va_start(list, nbr);
    for (int i = 0; i < nbr; ++i){
        if (exit_in == 2)
            my_error(va_arg(list, char *));
        else
            my_putstr(va_arg(list, char *));
    }
    va_end(list);
    return exit_code;
}
