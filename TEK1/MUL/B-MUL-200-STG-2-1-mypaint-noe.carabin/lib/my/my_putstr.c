/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr
*/

#include "../../includes/my.h"

int my_putstr(char const *str)
{
    char *arr = (char *) str;
    int index = 0;

    while (arr[index] != '\0'){
        my_putchar(arr[index]);
        index++;
    }
    return 0;
}
