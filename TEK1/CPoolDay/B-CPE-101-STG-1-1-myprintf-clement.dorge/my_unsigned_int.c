/*
** EPITECH PROJECT, 2023
** formyprintf
** File description:
** my_unsigned_int.c
*/

#include <stddef.h>

long long int my_unsigned_int(int nbr, char *forme, int largeur, int precision)
{
    long long int b = 4294967296;

    if (nbr > 2147483647)
        return;
    if (nbr < 0)
        b += nbr;
    else
        b = nbr;
    return b;
}
