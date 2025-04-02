/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a char
*/

#include <stdarg.h>
#include <stddef.h>

int mini_c(va_list parametersInfos, char *forme, int largeur, int precision)
{
    char c[2] = { '\0' };

    c[0] = va_arg(parametersInfos, int);
    my_putstr(c, forme, largeur, precision);
}
