/*
** EPITECH PROJECT, 2023
** my_two_complement.c
** File description:
** my_two_complement
*/

#include "../../includes/my.h"

static char tc_two_complement2(char *str, int i, char *cache)
{
    if (str[i] == '0' && *cache == '1'){
        *cache = '0';
        return '1';
    }
    if (str[i] == '1' && *cache == '1'){
        return '0';
    }
    if (str[i] == '1' && *cache == '0'){
        return '1';
    }
}

char *tc_two_complement(char *str)
{
    int length = my_strlen(str);
    char back = '\n';
    char cache = '1';

    str = tc_rev_bin(str);
    str = my_revstr(str);
    for (int i = 0; i < length; i++){
        str[i] = tc_two_complement2(str, i, &cache);
    }
    str = my_revstr(str);
    return str;
}
