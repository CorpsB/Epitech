/*
** EPITECH PROJECT, 2023
** my_rev_bin.c
** File description:
** my_rev_bin.c
*/

#include "../../includes/my.h"

char *tc_rev_bin(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length; i++){
        if (str[i] == '1'){
            str[i] = '0';
        } else {
            str[i] = '1';
        }
    }
    return str;
}
