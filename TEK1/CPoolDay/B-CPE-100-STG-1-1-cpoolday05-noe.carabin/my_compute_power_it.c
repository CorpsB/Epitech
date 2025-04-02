/*
** EPITECH PROJECT, 2023
** my compute power it
** File description:
** write the power number
*/

int calculate(int nb, int p)
{
    int valeur_initiale = nb;

    if (p < 0) {
        return (0);
            }
    if (p == 0) {
        return (1);
    }
    for (; p != 1; p --) {
        nb = nb * valeur_initiale;
    }
}

int my_compute_power_it(int nb, int p)
{
    int resultat = calculate(nb, p);

    if (p == 0) {
        return (1);
    }
    return (resultat);
}
