/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a string
*/

#include <stdarg.h>
#include <stddef.h>

int mini_s(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_putstr(va_arg(parametersInfos, char *), forme, largeur, precision);
}
