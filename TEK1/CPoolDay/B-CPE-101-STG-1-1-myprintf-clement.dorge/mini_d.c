/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** mini_d
*/

#include <stdarg.h>
#include <stddef.h>

int mini_d(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_put_nbr(va_arg(parametersInfos, int), forme, largeur, precision);
}
