/*
** EPITECH PROJECT, 2023
** KJ_INT_TO_STR
** File description:
** Tranform an integer into a string.
*/

#include "../../../include/my.h"
char *s_convert_n(long long nb)
{
    int size = n_size(nb);
    char *result = malloc((sizeof(char) * size) + 1);
    int i = size - 1;

    if (result == NULL)
        return NULL;
    result[i + 1] = '\0';
    for (; i >= 0; --i){
        result[i] = 48 + (nb % 10);
        nb /= 10;
    }
    return (result);
}
