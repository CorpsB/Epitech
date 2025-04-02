/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** is_alpha_num.c
*/

#include "../my.h"

/**
 * Cette fonction renvoie true si la string n'est composé que de chiffress et
 * de lettres (majuscules / minuscules).
*/
bool is_alpah_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < 'a' || str[i] > 'z') && str[i] != '_')
            return false;
    }
    return true;
}
