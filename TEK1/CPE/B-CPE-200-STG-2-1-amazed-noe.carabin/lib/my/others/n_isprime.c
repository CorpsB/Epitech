/*
** EPITECH PROJECT, 2023
** MY_IS_PRIME
** File description:
** Is it a prime number ?
*/

#include "../../../include/my.h"
int n_isprime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = nb -1; i > 1; --i)
        if (nb % i == 0)
            return (0);
    return (1);
}
