/*
** EPITECH PROJECT, 2024
** MY_PUTNBR
** File description:
** Print a number.
*/

#include "../../../include/my.h"
void my_putnbr(long long nb, int port)
{
    int size;
    int power;

    if (nb < 0){
        my_putchar('-', port);
        nb *= (-1);
    }
    size = n_size(nb) - 1;
    for (; size > -1; --size){
        power = n_power(10, size);
        my_putchar(48 + nb / power, port);
        nb -= ((nb / power) * power);
    }
}
