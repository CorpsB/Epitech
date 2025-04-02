/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** my_compute_power_rec
*/

#include "../../includes/my.h"

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p == 0){
        return 1;
    } else if (p < 0){
        return 0;
    }
    result *= my_compute_power_rec(nb, p - 1);
    return result;
}
