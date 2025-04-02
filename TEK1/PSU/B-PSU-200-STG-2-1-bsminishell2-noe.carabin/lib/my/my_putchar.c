/*
** EPITECH PROJECT, 2023
** My putchar
** File description:
** Write a character
*/

#include "../my.h"

/**
 * Cette fonction permet d'écrire des caractères dans le terminal.
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}
