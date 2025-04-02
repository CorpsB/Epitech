/*
** EPITECH PROJECT, 2023
** flag_u.c
** File description:
** flag_u.c
*/

#include "../my.h"
#include <stdlib.h>
#include <stdio.h>

static int conv(int nbr)
{
    int nbr2;

    if (nbr == 0) {
        my_putchar('0');
        return 0;
    }
    if (nbr >= 10)
        conv(nbr / 10);
    my_putchar(nbr % 10 + '0');
}

int flag_u(unsigned int nb)
{
    if (nb <= 4294967295)
        conv(nb);
}
