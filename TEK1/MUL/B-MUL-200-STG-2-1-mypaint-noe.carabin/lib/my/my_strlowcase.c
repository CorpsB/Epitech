/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** my_strlowcase
*/

#include "../../includes/my.h"

char *my_strlowcase(char *str)
{
    int ascii_char;

    for (int i = 0; i < my_strlen(str); i++){
        ascii_char = (int)str[i];
        if (str[i] != '\0' && ascii_char >= 65 && ascii_char <= 90){
            str[i] = ascii_char + 32;
        }
    }
    return str;
}
