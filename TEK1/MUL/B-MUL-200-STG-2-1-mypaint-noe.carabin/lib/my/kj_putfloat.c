/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** Return a float_number.
*/

#include "../../includes/my.h"

int kj_putfloat(double nb, int virg)
{
    char *res = kj_getfloat(nb, virg);

    my_putstr(res);
    free(res);
    return (0);
}
