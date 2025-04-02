/*
** EPITECH PROJECT, 2023
** KJ_REVERSE_BASE
** File description:
** Put a number back into base 10.
*/

#include "../../../include/my.h"

long long n_revbase(char *nb, int base, int max)
{
    int result = 0;
    int j = 0;

    for (int i = 0; i < max; ++i){
        for (j = 0; BASE_36[j] != nb[i]; ++j);
        result += (j * n_power(base, max - 1 - i));
    }
    return (result);
}
