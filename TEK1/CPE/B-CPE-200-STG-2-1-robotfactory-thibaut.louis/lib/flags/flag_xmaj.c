/*
** EPITECH PROJECT, 2023
** flag_xmaj.c
** File description:
** flag_xmaj.c
*/

#include "../my.h"

static int dechex1(int i, char hexadecimal[i])
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

int flag_xmaj(int nb)
{
    char hexadecimal[20];
    int i = 0;
    int reste;

    while (nb > 0) {
        reste = nb % 16;
        if (reste < 10) {
            hexadecimal[i] = reste + '0';
        } else {
            hexadecimal[i] = reste - 10 + 'A';
        }
        nb /= 16;
        i++;
    }
    dechex1(i, hexadecimal);
    return 0;
}
