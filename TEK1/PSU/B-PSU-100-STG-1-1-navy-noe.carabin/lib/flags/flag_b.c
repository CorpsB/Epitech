/*
** EPITECH PROJECT, 2023
** flag_b.c
** File description:
** flag_b.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
}

static char *my_rev_bin(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0')
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}

static char *my_conv_bin(int nb)
{
    char *str;
    int rest = 0;
    int count = 0;
    int i = 0;

    for (; nb != 0; count++) {
        nb /= 2;
    }
    str = malloc(sizeof(char) * count);
    for (; str[i] != '\0'; i++){
        rest = nb % 2;
        nb = nb / 2;
        str[i] = 48 + rest;
    }
    str[i] = '\0';
    my_putstr(str);
    free(str);
}

int flag_b(int nb)
{
    my_conv_bin(nb);
    return 0;
}

int main(void)
{
    int nb = 42;

    flag_b(nb);
    return 0;
}
