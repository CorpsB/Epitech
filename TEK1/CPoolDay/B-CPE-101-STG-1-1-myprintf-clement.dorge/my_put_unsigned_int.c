/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** my_put_unsigned_int.c
*/

#include <stddef.h>

void my_put_unsigned_int(long long int a, char *forme, int largeur,
    int precision)
{
    if (a < 0)
        a = a + 4294967296;
    my_put_nbr(a, forme, largeur, precision);
}
