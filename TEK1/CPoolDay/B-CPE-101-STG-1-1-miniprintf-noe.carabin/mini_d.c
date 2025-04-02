/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** mini_d
*/

int my_put_nbr(int a)
{
    int b = a;
    int cpt = 0;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (a > 9) {
        my_put_nbr(a / 10);
    }
    my_putchar(a % 10 + 48);
}

int mini_d(int nbr)
{
    my_put_nbr(nbr);
}
