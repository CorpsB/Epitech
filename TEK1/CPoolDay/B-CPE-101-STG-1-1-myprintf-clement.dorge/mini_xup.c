/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** for a printf x
*/

#include <stdarg.h>
#include <stddef.h>

int mini_xup(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_put_hexa_up(va_arg(parametersInfos, int), forme, largeur, precision);
}
