/*
** EPITECH PROJECT, 2023
** My compute rec
** File description:
** calculate power
*/

#include "../my.h"

static int calcul(int nb, int p)
{
    int result;

    if (p == 0) {
        return (nb);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

/**
 * Cette fonction renvoie un nombre à sa puissance.
 * @param nb Le nombre.
 * @param p Sa puissance.
*/
int my_compute_power_rec(int nb, int p)
{
    if (nb == 0 || p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    return (calcul(nb, p));
}
