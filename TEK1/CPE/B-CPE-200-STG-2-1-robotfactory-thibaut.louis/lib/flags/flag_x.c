/*
** EPITECH PROJECT, 2023
** flag_x.c
** File description:
** flag_x.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

static int dechex2(int i, char hexadecimal[i])
{
    if (i == 0) {
        my_putchar('0');
    } else {
        for (int j = i - 1; j >= 0; j--) {
            my_putchar(hexadecimal[j]);
        }
        my_putchar('\n');
    }
    return 0;
}

int flag_x(int nb)
{
    char hexadecimal[20];
    int i = 0;
    int reste;

    my_putchar('0');
    my_putchar('x');
    while (nb > 0) {
        reste = nb % 16;
        if (reste < 10) {
            hexadecimal[i] = reste + '0';
        } else {
            hexadecimal[i] = reste - 10 + 'a';
        }
        nb /= 16;
        i++;
    }
    dechex2(i, hexadecimal);
    return 0;
}
