/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** mini_e.c
*/

#include <stdarg.h>
#include <stddef.h>

int mini_x(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_put_hexa_low(va_arg(parametersInfos, int), forme, largeur, precision);
}
