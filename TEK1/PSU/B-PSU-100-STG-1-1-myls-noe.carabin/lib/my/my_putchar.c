/*
** EPITECH PROJECT, 2023
** My putchar
** File description:
** Write a character
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
