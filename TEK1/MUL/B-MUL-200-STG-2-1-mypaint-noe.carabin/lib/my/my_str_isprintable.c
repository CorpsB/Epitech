/*
** EPITECH PROJECT, 2023
** my_str_isprintable.c
** File description:
** my_str_isprintable
*/

#include "../../includes/my.h"

int my_str_isprintable(char const *str)
{
    if (str == "\0"){
        return 1;
    }
    for (int i = 0; my_strlen(str); i++){
        if (str[i] < 32 || str[i] == 127){
            return 0;
        }
    }
    return 1;
}
