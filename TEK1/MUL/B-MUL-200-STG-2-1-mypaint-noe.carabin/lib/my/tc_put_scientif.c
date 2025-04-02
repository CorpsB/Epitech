/*
** EPITECH PROJECT, 2023
** TC_PUTSCIENTIF
** File description:
** Put a float number to scientif.
*/

#include "../../includes/my.h"

static void tc_put_scientif_2(double nb, char exp_sign,
    int multiplier, int virg)
{
    if (nb > 9.999999){
        nb = (double)nb / 10.0;
        multiplier++;
    }
    kj_putfloat(nb, virg);
    my_putchar('e');
    my_putchar(exp_sign);
    if (multiplier <= 9)
        my_putchar('0');
    my_putnbr(multiplier);
}

void tc_put_scientif(double nb, int virg)
{
    int multiplier = 0;
    char exp_sign = '+';
    char sign = '+';

    if (nb < 0){
        sign = '-';
        nb = -nb;
    }
    if (nb > 0 && nb < 1){
        for (; nb < 1.0; multiplier++)
            nb *= 10;
        exp_sign = '-';
    } else {
        for (; nb >= 10; multiplier++)
            nb = (double)(nb / 10.0);
    }
    if (sign == '-')
        my_putchar(sign);
    tc_put_scientif_2(nb, exp_sign, multiplier, virg);
}
