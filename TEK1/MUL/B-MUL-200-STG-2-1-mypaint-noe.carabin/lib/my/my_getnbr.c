/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "../../includes/my.h"

static int is_num_neg(char const *str, int j, int neg_modifier)
{
    int neg = 0;

    if (str[j] == '+' || str[j] == '-' && neg_modifier == -1){
        neg = 1;
    } else if (str[j] == '-'){
        neg = -1;
    }
    return neg;
}

int my_getnbr(char const *str)
{
    long long num = 0;
    int neg_modifier = 1;
    int j = 0;

    for (; str[j] != '\0'; j++){
        if (str[j] == '-' || str[j] == '+')
            neg_modifier = is_num_neg(str, j, neg_modifier);
        else
            break;
    }
    while (str[j] != '\0'){
        if (str[j] >= '0' && str[j] <= '9')
            num = num * 10 + (str[j] - 48);
        else
            break;
        j++;
    }
    if (num * neg_modifier > 2147483647 || num * neg_modifier < -2147483648)
        return 0;
    return num * neg_modifier;
}
