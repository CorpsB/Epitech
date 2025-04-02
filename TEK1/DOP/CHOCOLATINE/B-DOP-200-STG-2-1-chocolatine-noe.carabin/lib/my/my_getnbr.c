/*
** EPITECH PROJECT, 2023
** my get number
** File description:
** Convert str to nbr, if no nbr return -1
*/

#include "my.h"

int my_getnbr(char *str)
{
    int result = 0;
    int i = 0;

    for (; str[i] < 57 && str[i] > 48; (i)++) {
        result = result * 10;
        result += (str[i] - 48);
    }
    if (i == 0)
        result == (-1);
    return result;
}
