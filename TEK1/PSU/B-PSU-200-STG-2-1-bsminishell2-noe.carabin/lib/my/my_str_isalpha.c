/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** cpool day 6
*/

#include "../my.h"

/**
 * Cette fonction renvoie un booléen true si la string ne contient que des
 * lettres (majuscules ou minuscules)
*/
int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] < 'A' || str[i] > 'Z') &&
    (str[i] < 'a' || str[i] > 'z') && str[i] != '_')
        return false;
    }
    return true;
}
