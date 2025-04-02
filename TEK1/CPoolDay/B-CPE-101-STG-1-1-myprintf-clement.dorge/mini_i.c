/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a long
*/

#include <stdarg.h>
#include <stddef.h>

int mini_i(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_put_nbr(va_arg(parametersInfos, int), forme, largeur, precision);
}
