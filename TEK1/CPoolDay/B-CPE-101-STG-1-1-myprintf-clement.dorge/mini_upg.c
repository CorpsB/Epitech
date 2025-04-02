/*
** EPITECH PROJECT, 2023
** PrintF
** File description:
** %g and %G
*/

#include <stdarg.h>
#include <stddef.h>

static int nbr_len(int nbr)
{
    int cpt = 0;

    for (; nbr > 0; cpt ++) {
    nbr = nbr / 10;
    }
    return (cpt);
}

int mini_upg(double nbr, char *forme, int largeur, int precision)
{
    int a = nbr;

    if (precision == 'NULL') {
        if (nbr < 1000000 && nbr > (-1000000)) {
            precision = 3;
            mini_f(nbr, forme, largeur, precision);
            return 0;
        }
        if (nbr_len(a) == 6) {
            precision = 5;
            my_put_nbr(a, forme, largeur, precision);
        return 0;
        }
    }
    mini_ee(nbr);
}

mini_gg(va_list parametersInfos, char *forme, int largeur, int precision)
{
    double nbr = va_arg(parametersInfos, double);

    mini_upg(nbr, forme, largeur, precision);
}
