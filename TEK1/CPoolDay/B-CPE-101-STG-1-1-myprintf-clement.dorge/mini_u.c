/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a char
*/

#include <stdarg.h>
#include <stddef.h>

int mini_u(va_list parametersInfos, char *forme, int largeur, int precision)
{
    long long int b = my_unsigned_int
    (va_arg(parametersInfos, int), forme, largeur, precision);

    my_put_unsigned_int(b);
}
