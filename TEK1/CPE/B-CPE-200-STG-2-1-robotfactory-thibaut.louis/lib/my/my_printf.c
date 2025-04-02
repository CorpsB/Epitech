/*
** EPITECH PROJECT, 2023
** mini_my_printf.c
** File description:
** my_printf
*/

#include "../my.h"

static int flag_reste(char c, va_list list)
{
    switch (c) {
    case 'G':
        return flag_g_maj(va_arg(list, double));
    case 'n':
        return flag_n(va_arg(list, char *));
    case 'o':
        return flag_o(va_arg(list, int));
    case '%':
        return flag_pourc();
    case 's':
        return flag_s(va_arg(list, char *));
    case 'u':
        return flag_u(va_arg(list, int));
    case 'x':
        return flag_x(va_arg(list, int));
    case 'X':
        return flag_xmaj(va_arg(list, int));
    }
}

static int flag(char c, va_list list)
{
    switch (c) {
    case 'c':
        return flag_c(va_arg(list, int));
    case 'd':
        return flag_d(va_arg(list, int));
    case 'i':
        return flag_d(va_arg(list, int));
    case 'e':
        return flag_e(va_arg(list, double), 0);
    case 'E':
        return flag_e(va_arg(list, double), 1);
    case 'f':
        return flag_f(va_arg(list, double));
    case 'F':
        return flag_f(va_arg(list, double));
    default:
        return flag_reste(c, list);
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            flag(format[i], list);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return 0;
}
