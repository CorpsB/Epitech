/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** my_find_prime_sup
*/

#include "../../includes/my.h"

int my_find_prime_sup(int nb)
{
    int result = 0;

    if (nb == 0 || nb == 1){
        return 2;
    }
    for (int i = 1; i < 32767; i++){
        result = my_is_prime(nb + i);
        if (result == 1){
            return nb + i;
        }
    }
    return 0;
}
