/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** fonction qui affiche, un par un, les caractères d'une chaîne.
*/

#include "../my.h"

int my_putstr(char const *str)
{
    if (*str == 48) {
        return 0;
    }
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
}
