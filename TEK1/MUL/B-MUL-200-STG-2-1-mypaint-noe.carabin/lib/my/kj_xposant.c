/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_POWER_REC
** File description:
** An recursive function that returns
** the first argument raised to the power
** p, where p is the second argument.
*/

#include "../../includes/my.h"

unsigned long long int kj_xposant(int nb, int p)
{
    unsigned long long int result = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (; p > 1; --p)
        result *= nb;
    return (result);
}
