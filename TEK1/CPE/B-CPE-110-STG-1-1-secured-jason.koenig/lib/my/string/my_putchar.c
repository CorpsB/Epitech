/*
** EPITECH PROJECT, 2023
** MY_PUTCHAR
** File description:
** Print a character.
*/

#include "../../../include/my.h"
void my_putchar(char c)
{
    write(1, &c, 1);
}
