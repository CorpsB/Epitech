/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** task03 my_revstr.c
*/

#include "../../my.h"

static int my_strlenv2(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char char_temp;
    int first_char;
    int last_char;

    last_char = my_strlenv2(str) - 1;
    first_char = 0;
    while (first_char < last_char) {
        char_temp = str[first_char];
        str[first_char] = str[last_char];
        str[last_char] = char_temp;
        first_char = first_char + 1;
        last_char = last_char - 1;
    }
    return (str);
}
