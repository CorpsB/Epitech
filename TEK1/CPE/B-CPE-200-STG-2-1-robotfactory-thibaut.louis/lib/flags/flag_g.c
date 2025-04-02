/*
** EPITECH PROJECT, 2023
** flag_g.c
** File description:
** flag_g.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

int flag_g(double nb)
{
    if (nb > 10000)
        flag_e(nb, 0);
    else
        flag_f(nb);
    return 0;
}
