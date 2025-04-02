/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a nbr with maybe an + or ' ' before
*/

static int nbr_len(int nbr)
{
    int cpt = 0;

    for (; nbr > 0; cpt ++) {
    nbr = nbr / 10;
    }
    return (cpt);
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

int my_put_nbr(int a, char *forme, int largeur, int precision)
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
    my_put_stnbr(a);
    if (precision == 'NULL' && (forme[0] == '-' || forme[1] == '-'))
        for (int cpt = 0; nbr_len(a) + cpt + j < largeur; cpt++) {
            my_putchar(' ');
        }
}

int my_put_stnbr(int a)
{
    long long int b = a;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (b == -2147483648) {
        my_putchar('2');
        my_put_stnbr(147483648);
    }
    if (a > 9) {
        my_put_stnbr(a / 10);
    }
    if (a % 10 + 48 != 40)
        my_putchar(a % 10 + 48);
}
