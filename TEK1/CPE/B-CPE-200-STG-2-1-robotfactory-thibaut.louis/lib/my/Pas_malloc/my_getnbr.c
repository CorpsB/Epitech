/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-thibaut.louis
** File description:
** my_atoi.c
*/

#include "../../my.h"

int my_getnbr(const char *str)
{
    int result = 0;
    int sign = 1;

    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    while (my_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}
