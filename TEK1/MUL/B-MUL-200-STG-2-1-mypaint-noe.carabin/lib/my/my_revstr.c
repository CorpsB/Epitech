/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** my_revstr
*/

#include "../../includes/my.h"

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}
