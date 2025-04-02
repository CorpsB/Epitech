/*
** EPITECH PROJECT, 2023
** my_compute_power_it.c
** File description:
** task03 my_compute_power_it.c
*/

int my_compute_power_it(int nb, int p)
{
    int resultat = nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    } else {
        for (int i = p; i > 1; i--) {
            resultat = resultat * nb;
        }
        return (resultat);
    }
}
