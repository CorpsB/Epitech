/*
** EPITECH PROJECT, 2023
** float.c
** File description:
** écrit des floats
*/

#include "../my.h"

int flag_f(double nb)
{
    int cb = (int)nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_put_nbr(cb);
    my_putchar('.');
    nb -= (double)cb;
    for (int i = 0; i < 6; i++) {
        nb *= 10.0;
        cb = (int)nb;
        my_putchar(48 + cb);
        nb -= (double)cb;
    }
    return 0;
}
