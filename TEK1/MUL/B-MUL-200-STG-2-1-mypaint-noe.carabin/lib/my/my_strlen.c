/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen
*/

#include "../../includes/my.h"

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0'){
        index++;
    }
    return (index);
}
