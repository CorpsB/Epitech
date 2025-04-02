/*
** EPITECH PROJECT, 2023
** factorial(without recusrsivity)
** File description:
** Write the factorial without recursivity
*/

int my_compute_factorial_it(int nb)
{
    int multiplicateur = 1;

    if (nb == 0) {
        return (1);
            }
    if (nb < 0 || nb >= 13) {
        return (0);
            }
    for (; nb != 0 ; nb--) {
        multiplicateur = multiplicateur * nb;
    }
    return (multiplicateur);
}
