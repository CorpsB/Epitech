/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-thomas.camuset
** File description:
** my_printerror
*/

#include "../../includes/my.h"

static void print_error(char *str, int exit)
{
    write(exit, str, my_strlen(str));
}

int print_exit(int exit, int exit_code, int nb, ...)
{
    va_list list;

    va_start(list, nb);
    for (int i = 0; i < nb; i++)
        print_error(va_arg(list, char *), exit);
    va_end(list);
    return exit_code;
}
