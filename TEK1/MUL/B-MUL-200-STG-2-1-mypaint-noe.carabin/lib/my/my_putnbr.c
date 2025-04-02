/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "../../includes/my.h"

int my_putnbr(int nb)
{
    if (nb > 9) {
        my_putnbr(nb / 10);
    }
    my_putchar((nb % 10) + 48);
}
