/*
** EPITECH PROJECT, 2023
** prime number
** File description:
** write prime number that are equal or greather than the nb number
*/

int my_is_prime_test(int nb)
{
    int compteur = 2;

    for (; compteur != nb; compteur ++) {
        if (nb % compteur == 0) {
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb )
{
    if (nb <= 0) {
        return (2);
    }
    for (; my_is_prime_test(nb) == 0; nb++) {
    }
    return (nb);
}
