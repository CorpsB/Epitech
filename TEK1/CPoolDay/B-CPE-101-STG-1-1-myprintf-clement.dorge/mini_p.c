/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** mini_p.c
*/

#include <stdarg.h>
#include <stddef.h>

int mini_p(va_list parametersInfos, char *forme, int largeur, int precision)
{
    my_pointer(va_arg(parametersInfos, int *), forme, largeur, precision);
}
