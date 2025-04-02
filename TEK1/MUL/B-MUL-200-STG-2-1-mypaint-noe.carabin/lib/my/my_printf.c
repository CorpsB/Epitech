/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-minishell1-thomas.camuset
** File description:
** my_printf
*/

#include "../../includes/my.h"

static int print_flag(char const *str, int i, va_list list)
{
    if (str[i + 1] == 'd' || str[i + 1] == 'i'){
        my_putnbr(va_arg(list, int));
        return i;
    }
    if (str[i + 1] == 'c'){
        my_putchar(va_arg(list, int));
        return i;
    }
    if (str[i + 1] == '%'){
        my_putchar('%');
        return i;
    }
    if (str[i + 1] == 's'){
        my_putstr(va_arg(list, char *));
        return i;
    }
    if (str[i + 1] == ' '){
        i = print_flag(str, i + 1, list);
    }
    return i;
}

int my_printf(char const *format, ...)
{
    int i = 0;
    va_list list;

    va_start(list, format);
    format = (char *)format;
    while (format[i] != '\0'){
        if (format[i] == '%'){
            i = print_flag(format, i, list);
            i++;
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    return 0;
}
