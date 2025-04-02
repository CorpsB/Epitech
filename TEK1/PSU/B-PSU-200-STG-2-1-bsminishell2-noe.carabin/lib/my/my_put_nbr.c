/*
** EPITECH PROJECT, 2023
** Put number
** File description:
** Write a number (lmimit = int)
*/

#include "../my.h"

/**
 * Cette fonction permet d'afficher des nombres dans le terminal.
*/
int my_put_nbr(int a)
{
    int b = a;
    int cpt = 0;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (a > 9) {
        my_put_nbr(a / 10);
    }
    my_putchar(a % 10 + 48);
}
