/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** Get a from a string.
*/

#include "../../../include/my.h"
static int my_getnbr_3rd(int *signe, long long *n)
{
    if ((*n * *signe) > 2147483647 ||
    (*n * *signe) < -2147483648)
        return (0);
    return (1);
}

static int my_getnbr_2nd(char const *str, int *signe, int i, long long *n)
{
    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            *signe *= (-1);
    } else if (str[i] >= 48 && str[i] <= 57){
        *n = (*n * 10) + (str[i] - 48);
        return (my_getnbr_3rd(signe, n));
    } else {
        return (2);
    }
    return (1);
}

static int is_break(int *breaker, int result)
{
    if (result == 2)
        *breaker = 1;
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int breaker = 0;
    int result;
    long long n = 0;

    for (int i = 0; str[i] != '\0' && breaker == 0; ++i){
        result = my_getnbr_2nd(str, &signe, i, &n);
        is_break(&breaker, result);
        if (result == 0)
            return (0);
    }
    return (n * signe);
}
