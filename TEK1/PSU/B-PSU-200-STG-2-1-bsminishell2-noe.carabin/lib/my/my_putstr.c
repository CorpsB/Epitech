/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** write one by one a caracter sting
*/

#include "../my.h"

/**
 * Cette fonction permet d'écrire une string dans le terminal.
*/
int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        my_putchar(str[i]);
    }
}
