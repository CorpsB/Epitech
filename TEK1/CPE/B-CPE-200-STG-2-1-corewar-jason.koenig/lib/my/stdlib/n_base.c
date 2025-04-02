/*
** EPITECH PROJECT, 2023
** KJ_CONVERT_BASE
** File description:
** Convert a integer into a given base.
*/

#include "../../../include/my.h"

char *n_base(unsigned long long nb, int base)
{
    char *result = my_strdup("");
    char carac[] = "#";

    while (nb > 0){
        carac[0] = BASE_36[nb % base];
        result = my_strcat(result, carac);
        nb /= base;
    }
    return s_reverse(result);
}

char *n_base_zero(unsigned long long nb, int base)
{
    char *result = my_strdup("00000000");
    int i = 0;

    while (nb > 0){
        result[i] = BASE_36[nb % base];
        nb /= base;
        ++i;
    }
    return s_reverse(result);
}
