/*
** EPITECH PROJECT, 2023
** sum number
** File description:
** make a sum
*/

#include <stdarg.h>

int sum_numbers (int n, ...)
{
    int result = 0;
    va_list a_lot_nbr;
    va_start(a_lot_nbr, n);

    for (int cpt = 0; cpt < n; cpt++) {
        result = result + va_arg(a_lot_nbr, int);
    }
    va_end(a_lot_nbr);
    return result;
}

int main(int ac, char **av)
{
    printf("%d", sum_numbers( 4, 5, 5, 5, 5, 2));
}
