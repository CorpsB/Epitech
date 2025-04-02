/*
** EPITECH PROJECT, 2023
** myprintf
** File description:
** my_pointer.c
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

void my_pointer(int *ptr, char *forme, int largeur, int precision)
{
    uintptr_t address = (uintptr_t)ptr;
    char hexChars[] = "0123456789abcdef";
    char hexAddress[16];
    int stop = 0;
    char result[18];

    for (int i = 15; i >= 0; i--) {
        hexAddress[i] = hexChars[address & 0xF];
        address >>= 4;
    }
    result[0] = '0';
    result[1] = 'x';
    for (int i = 0; i < 16; i++) {
        while (hexAddress[i] == '0' && stop == 0)
            i++;
        if (stop == 0)
            stop = 1;
        result[stop++ + 1] = hexAddress[i];
    }
    my_putstr(result, forme, largeur, precision);
}
