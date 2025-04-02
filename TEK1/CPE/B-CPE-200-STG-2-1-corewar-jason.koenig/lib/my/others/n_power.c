/*
** EPITECH PROJECT, 2023
** KJ_XPOSANT
** File description:
** Put a number into the given power.
*/

#include "../../../include/my.h"
unsigned long long n_power(int nb, int p)
{
    unsigned long long result = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (; p > 1; --p)
        result *= nb;
    return (result);
}
