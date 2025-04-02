/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** str_len_to.c
*/

#include "../my.h"

/**
 * La focntion renvoie la distance entre l'index reçus, et le separateur.
 * WARNING: Si elle ne trouve pas de separator elle fonctionne comme strn_len.
 * WARNING: Elle renvoie -1 si la string vaut NULL.
 * @param str La string.
 * @param index L'index de début de recherche (0 pour commencer au début).
*/
int str_len_to(char *str, int index, char separator)
{
    int a = index;

    if (str == NULL)
        return -1;
    for (; str[index] != '\0' && str[index] != separator; index++);
    return (index - a);
}
