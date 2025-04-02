/*
** EPITECH PROJECT, 2023
** PrintF
** File description:
** for a e
*/

#include <stdarg.h>
#include <stddef.h>

static int nbr_len(int nbr, char *forme, int precision)
{
    if (precision == NULL) {
        precision = 6;
    }
    return (precision + 5);
}

static int my_put_nbrnext(int a, char *forme, int *i, int *j)
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

int sfeeselector(int a, char *forme, int largeur, int precision)
{
    int i = 1;
    int j = 0;

    my_put_nbrnext(a, forme, &i, &j);
    if (largeur != 'NULL' && precision == 'NULL' && (forme[0] != '-'
    && forme[1] != '-'))
            for (int cpt = 0; nbr_len(a, forme, precision) + cpt + j < largeur;
            cpt++)
                my_putchar('0');
    if (precision != 'NULL')
        for (int cpt = 0; nbr_len(a, forme, precision) + cpt < precision;
        cpt++)
            my_putchar('0');
    main_ee(a, forme, largeur, precision);
    if (precision == 'NULL' && (forme[0] == '-' || forme[1] == '-'))
        for (int cpt = 0; nbr_len(a, forme, precision) + cpt + j < largeur;
        cpt++)
            my_putchar(' ');
}

static int my_put_enbr(int a)
{
    long long int b = a;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (b == -2147483648) {
        my_putchar('2');
        my_put_enbr(147483648);
    }
    if (a > 9) {
        my_put_enbr(a / 10);
    }
    if (a % 10 + 48 != 40)
        my_putchar(a % 10 + 48);
}

static int aff_f(double nbr, int precision)
{
    long long a = 0;
    int c = 0;
    int d = 0;

    a = nbr;
    nbr = nbr - a;
    my_put_enbr(a);
    my_putchar('.');
    for (int cpt = 0; cpt < precision; cpt ++) {
        if ((int) (nbr * 10) == 0) {
            my_putchar('0');
            nbr = nbr * 10;
        } else {
            nbr = nbr * 10;
            c = nbr;
            my_put_enbr(c);
            nbr = nbr - c;
        }
    }
    return 0;
}

static int big_nbr(double nbr, int precision)
{
    int cpt = 0;
    int a = 0;

    for (; nbr > 10;) {
        nbr = nbr / 10;
        cpt++;
    }
    aff_f(nbr, precision);
    my_putchar('E');
    my_putchar('+');
    if (cpt < 10) {
        my_putchar('0');
    }
    my_put_enbr(cpt);
}

static int little_nbr(double nbr, int precision)
{
    int cpt = 0;
    int a = 0;

    for (; nbr < 1;) {
        nbr = nbr * 10;
        cpt++;
    }
    aff_f(nbr, precision);
    my_putchar('E');
    my_putchar('-');
    if (cpt < 10) {
        my_putchar('0');
    }
    my_put_enbr(cpt);
}

int main_ee(double nbr, char *forme, int largeur, int precision)
{
    if (precision == NULL) {
        precision = 6;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 10) {
        big_nbr(nbr, precision);
    } else {
        little_nbr(nbr, precision);
    }
}

int mini_ee(va_list parametersInfos, char *forme, int largeur, int precision)
{
    main_ee(va_arg(parametersInfos, double), forme, largeur, precision);
}
