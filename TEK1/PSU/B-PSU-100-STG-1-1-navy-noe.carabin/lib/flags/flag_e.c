/*
** EPITECH PROJECT, 2023
** flag_e.c
** File description:
** flag_e.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

static int maj(int i)
{
    if (i == 0)
        my_putchar('e');
    else
        my_putchar('E');
}

static int inf(double nb, int i)
{
    int p = 0;

    for (p; nb >= 1; p++)
        nb *= 10;
    flag_f(nb);
    maj(i);
    my_putchar('-');
    my_put_nbr(p);
    return 0;
}

static int sup(double nb, int i)
{
    int p = 0;

    for (; nb > 10; p++) {
        nb = nb / 10;
    }
    flag_f(nb);
    maj(i);
    my_putchar('+');
    my_put_nbr(p);
    return 0;
}

int flag_e(double nb, int i)
{
    if (nb < 1 && nb > 0 || nb < 0 && nb > -1)
        inf(nb, i);
    else
        sup(nb, i);
    return 0;
}
