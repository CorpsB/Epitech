/*
** EPITECH PROJECT, 2023
** flag_o.c
** File description:
** flag_o.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

static int my_put_nbr2(int nbr)
{
    int nbr2;

    if (nbr >= 8) {
        nbr2 = nbr % 8;
        nbr = nbr / 8;
        my_put_nbr2(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
    return (0);
}

int flag_o(int nbr)
{
    int nbr2;

    if (nbr >= 8) {
        nbr2 = nbr % 8;
        nbr = nbr / 8;
        my_put_nbr2(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
    return (0);
}
