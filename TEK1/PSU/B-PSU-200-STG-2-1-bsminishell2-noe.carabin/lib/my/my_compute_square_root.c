/*
** EPITECH PROJECT, 2023
** square root
** File description:
** write the square root
*/

#include "../my.h"

static int calcul2(int nb)
{
    int racine_test = 1;

    if (racine_test <= 0) {
            return (0);
    }
    for (; racine_test < nb; racine_test ++) {
        if (racine_test * racine_test == nb) {
            return (racine_test);
        }
    }
    return (0);
}

/**
 * Cette fonction renvoie un nombre au carré.
 * @param nb Le nombre.
*/
int my_compute_square_root(int nb)
{
    if (nb == 1) {
        return (1);
    }
    return (calcul2(nb));
}
