/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a long
*/

#include <stddef.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int nbr_len(long long int nbr)
{
    int cpt = 0;
    long long b = my_unsigned_int(nbr);

    if (b > 15)
        cpt += nbr_len(b / 16);
    if (b % 16 < 10)
        cpt = 1;
    else
        cpt = 1;
    return cpt;
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
    if (forme[3] == '#') {
        my_putchar('0');
        my_putchar('x');
    }
}

static int do_exa(int a)
{
    long long b = my_unsigned_int(a);

    if (b > 15)
        do_exa(b / 16);
    if (b % 16 < 10)
        my_putchar(b % 16 + 48);
    else
        my_putchar(b % 16 + 55 + 32);
}

int my_put_hexa_low(int a, char *forme, int largeur, int precision)
{
    int i = 1;
    int j = 0;

    my_put_nbrnext(a, forme, &i, &j);
    if (largeur != 'NULL' && precision == 'NULL' && (forme[0] != '-'
    && forme[1] != '-'))
            for (int cpt = 0; nbr_len(a) + cpt + j < largeur; cpt++) {
                my_putchar('0');
            }
    if (precision != 'NULL')
        for (int cpt = 0; nbr_len(a) + cpt < precision; cpt++) {
            my_putchar('0');
        }
    do_exa(a);
    if (precision == 'NULL' && (forme[0] == '-' || forme[1] == '-'))
        for (int cpt = 0; nbr_len(a) + cpt + j < largeur; cpt++) {
            my_putchar(' ');
        }
}
