/*
** EPITECH PROJECT, 2023
** my get number
** File description:
** Convert str to nbr, if no nbr return -1
*/

#include "../my.h"

/**
 * Cette fonction prend une string et en extrait le nombre.
 * @param str La string.
*/
int my_getnbr(char *str)
{
    int result = 0;
    int i = 0;

    for (; str[i] != '\0'; (i)++) {
        if ((str[i] == '%' && i == 0) || (str[i] == ':' && i == 1) ||
        (str[i] == 'r' && i == 0))
            continue;
        if (str[i] < 57 && str[i] > 48) {
            result = result * 10;
            result += (str[i] - 48);
        }
    }
    if (i == 0)
        result == (-1);
    return result;
}
