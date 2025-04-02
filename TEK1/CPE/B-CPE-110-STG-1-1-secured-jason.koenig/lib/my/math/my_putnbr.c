/*
** EPITECH PROJECT, 2023
** MY_PUTNBR
** File description:
** Print a number.
*/

#include "../../../include/my.h"
void my_putnbr(long long number)
{
    char *result = kj_int_to_str(number);

    my_putstr(result);
    free(result);
}
