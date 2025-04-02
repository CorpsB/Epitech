/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** my_strcapitalize
*/

#include "../../includes/my.h"

static bool my_strcapitalize2(char *n_str, bool can_cap, int ascii_char, int i)
{
    if (can_cap == true){
        n_str[i] = ascii_char - 32;
    }
    can_cap = false;
    return can_cap;
}

static bool my_strcapitalize3(int ascii_char, bool can_cap)
{
    if (ascii_char == 32){
        can_cap = true;
    } else {
        can_cap = false;
    }
    return can_cap;
}

char *my_strcapitalize(char *str)
{
    char *n_str = my_strlowcase(str);
    int ascii_char;
    bool can_cap = true;

    for (int i = 0; i < my_strlen(n_str); i++){
        ascii_char = (int)n_str[i];
        if (ascii_char >= 97 && ascii_char <= 122){
            can_cap = my_strcapitalize2(n_str, can_cap, ascii_char, i);
        }
        can_cap = my_strcapitalize3(ascii_char, can_cap);
    }
    return n_str;
}
