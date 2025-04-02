/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** Display the caracter number
*/

#include "../my.h"

/**
 * Renvoie la taille de la string.
*/
int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}
