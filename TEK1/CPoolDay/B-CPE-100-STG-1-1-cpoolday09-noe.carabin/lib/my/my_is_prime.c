/*
** EPITECH PROJECT, 2023
** Is it prime number ?
** File description:
** Say if it's a prime number (=1) or not (=0).
*/

int my_is_prime(int nb)
{
    int compteur = 2;

    for (; compteur != nb; compteur ++) {
        if (nb % compteur == 0) {
            return (0);
        }
    }
    return (1);
}
