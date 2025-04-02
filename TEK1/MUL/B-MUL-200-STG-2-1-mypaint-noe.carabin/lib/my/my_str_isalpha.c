/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** my_str_isalpha
*/

#include "../../includes/my.h"

static int my_str_isalpha2(int ascii_char)
{
    if (ascii_char >= 65 && ascii_char <= 90){
        ;
    } else if (ascii_char >= 97 && ascii_char <= 122){
        ;
    } else {
        return 0;
    }
}

int my_str_isalpha(char const *str)
{
    int ascii_char;

    if (str[0] == '\0'){
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++){
        ascii_char = (int)str[i];
        my_str_isalpha2(ascii_char);
        if (my_str_isalpha2(ascii_char) == 0){
            return 0;
        }
    }
    return 1;
}
