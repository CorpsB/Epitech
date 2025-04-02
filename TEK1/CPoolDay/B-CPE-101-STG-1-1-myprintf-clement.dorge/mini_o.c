/*
** EPITECH PROJECT, 2023
** printf
** File description:
** octal
*/

#include <stdarg.h>
#include <stddef.h>

static int calculate(int nb, int p)
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

static int my_compute_power_it(int nb, int p)
{
    int resultat = calculate(nb, p);

    if (p == 0) {
        return (1);
    }
    return (resultat);
}

int under_flag(char *forme)
{
    if (forme[3] == '#') {
        my_putchar('0');
    }
}

static int octal(int nbr, char *forme, int largeur, int precision)
{
    int cpt = 1;
    int result = 0;

    under_flag(forme);
    if (nbr < 8) {
        my_put_nbr(nbr);
        return;
    }
    result = (nbr % 8);
    nbr = (float)nbr / 8;
    for (; nbr > 8; cpt++) {
        result = result + (nbr % 8) * (my_compute_power_it(10, cpt));
        nbr = (float)nbr / 8;
    }
    result = result + (nbr * (my_compute_power_it(10, cpt)));
    my_put_nbr(result, forme, largeur, precision);
}

int mini_o(va_list parametersInfos, char *forme, int largeur, int precision)
{
    int nbr = va_arg(parametersInfos, int);

    octal(nbr, forme, largeur, precision);
}
