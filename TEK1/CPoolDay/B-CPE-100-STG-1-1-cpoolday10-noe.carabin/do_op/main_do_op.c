/*
** EPITECH PROJECT, 2023
** do op
** File description:
** main fonction
*/
#include "selectop.h"

int do_op(int value1, char operator, int value2, int *error)
{
    char *test_op = malloc(sizeof(char) * 6);

    for (int compteur = 0; compteur < 5; compteur++) {
        printf("%c == %c\n", operator, OPERATORS_FUNCS[compteur].symbol[0]);
        if (operator == OPERATORS_FUNCS[compteur].symbol[0]) {
            return (OPERATORS_FUNCS[compteur].func(value1, value2, error));
        }
    }
    *error = 84;
    return 0;
}

int main(int ac, char **av)
{
    int value1 = get_nbr(av[1]);
    char operator = av[2][0];
    int value2 = get_nbr(av[3]);
    int error = 0;

    my_put_nbr(do_op(value1, operator, value2, &error));
    return (error);
}
