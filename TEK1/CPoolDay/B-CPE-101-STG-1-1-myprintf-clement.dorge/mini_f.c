/*
** EPITECH PROJECT, 2023
** printf
** File description:
** %f
*/

#include <stdarg.h>
#include <stddef.h>

static int my_put_nmnbr(int a)
{
    long long int b = a;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (b == -2147483648) {
        my_putchar('2');
        my_put_nmnbr(147483648);
    }
    if (a > 9) {
        my_put_nmnbr(a / 10);
    }
    if (a % 10 + 48 != 40)
        my_putchar(a % 10 + 48);
}

static int nbr_len(int nbr)
{
    int cpt = 0;

    for (; nbr > 0; cpt ++) {
        nbr = nbr / 10;
    }
    return (cpt);
}

static int flo_len(double nbr, int precision)
{
    int cpt = 0;
    int a = nbr;

    if (precision == NULL) {
        precision = 6;
    }
    cpt = nbr_len(a) + precision + 1;
    return (cpt);
}

static int aff_f(double nbr, int precision)
{
    long a = 0;
    int c = 0;
    int d = 0;

    a = nbr;
    nbr = nbr - a;
    my_put_nmnbr(a);
    my_putchar('.');
    for (int cpt = 0; cpt < precision; cpt ++) {
        if ((int) (nbr * 10) == 0) {
            my_putchar('0');
            nbr = nbr * 10;
        } else {
            nbr = nbr * 10;
            c = nbr;
            my_put_nmnbr(c);
            nbr = nbr - c;
        }
    }
    return 0;
}

int my_put_nbrnext(int a, char *forme, int *i, int *j)
{
    if (forme[0] == ' ' || forme[0] == '+') {
        if (a > 0) {
            my_putchar(forme[0]);
            *i--;
            *j++;
        }
    }
    if (forme[1] == ' ' || forme[1] == '+') {
        if (a > 0) {
            my_putchar(forme[1]);
            *i--;
            *j++;
        }
    }
}

int preaff_f(double nbr, int precision)
{
    if (precision == NULL) {
        precision = 6;
    }
    aff_f(nbr, precision);
}

int sf_traitement(double a, char *forme, int larg, int precision)
{
    int i = 1;
    int j = 0;

    my_put_nbrnext(a, forme, &i, &j);
    if (larg != NULL && precision == NULL && (forme[0] != '-'
    && forme[1] != '-'))
            for (int cpt = 0; flo_len(a, precision) + cpt + j < larg; cpt++) {
                my_putchar('0');
            }
    if (precision != NULL)
        for (int cpt = 0; flo_len(a, precision) + cpt < precision; cpt++) {
            my_putchar('0');
        }
    preaff_f(a, precision);
    if (precision == NULL && (forme[0] == '-' || forme[1] == '-'))
        for (int cpt = 0; flo_len(a, precision) + cpt + j < larg; cpt++) {
            my_putchar(' ');
        }
}

int mini_f(va_list parametersInfos, char *forme, int largeur, int precision)
{
    double nbr = va_arg(parametersInfos, double);

    sf_traitement(nbr, forme, largeur, precision);
}
