/*
** EPITECH PROJECT, 2023
** MY_PUTCHAR
** File description:
** Print a character.
*/

#include "../../../include/base/my.h"
void my_putchar(char c, int port)
{
    write(port, &c, 1);
}
