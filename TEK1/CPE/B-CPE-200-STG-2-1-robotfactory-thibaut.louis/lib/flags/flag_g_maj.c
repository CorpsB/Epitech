/*
** EPITECH PROJECT, 2023
** flag_G.c
** File description:
** flag_G.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

int flag_g_maj(double nb)
{
    if (nb > 10000)
        flag_e(nb, 1);
    else
        flag_f(nb);
    return 0;
}
