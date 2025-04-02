/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** mini_b.c
*/

#include <stdarg.h>
#include <stddef.h>

int mini_b(va_list parametersInfos)
{
    my_binary(va_arg(parametersInfos, int));
}
