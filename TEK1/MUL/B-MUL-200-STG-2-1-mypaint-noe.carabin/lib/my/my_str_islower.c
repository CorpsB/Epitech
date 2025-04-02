/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** my_str_islower
*/

#include "../../includes/my.h"

int my_str_islower(char const *str)
{
    int ascii_char;

    if (str[0] == '\0'){
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++){
        ascii_char = (int)str[i];
        if (ascii_char >= 97 && ascii_char <= 122){
            ;
        } else {
            return 0;
        }
    }
    return 1;
}
