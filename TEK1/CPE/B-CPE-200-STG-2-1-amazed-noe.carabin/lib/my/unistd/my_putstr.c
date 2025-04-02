/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** Print a string.
*/

#include "../../../include/my.h"
void my_putstr(char const *str, int port)
{
    write(port, str, my_strlen(str));
}
