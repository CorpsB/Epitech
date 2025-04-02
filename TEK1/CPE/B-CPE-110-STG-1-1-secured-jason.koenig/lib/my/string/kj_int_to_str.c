/*
** EPITECH PROJECT, 2023
** KJ_INT_TO_STR
** File description:
** Tranform an integer into a string.
*/

#include "../../../include/my.h"
char *kj_int_to_str(long long nb)
{
    char *result = malloc((sizeof(char) * kj_count_number(nb)) + 1);
    int i = kj_count_number(nb) - 1;

    result[i + 1] = '\0';
    for (; i >= 0; --i){
        result[i] = 48 + (nb % 10);
        nb /= 10;
    }
    return (result);
}
