/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** Display the caracter number
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0' ; i = i + 1) {
        printf("%c\n", str[i]);
        char_number = char_number + 1;
    }
    return (char_number);
}
