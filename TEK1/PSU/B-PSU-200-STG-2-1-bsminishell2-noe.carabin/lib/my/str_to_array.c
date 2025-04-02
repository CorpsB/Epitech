/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** str_to_array.c
*/

#include "../my.h"

/**
 * Cette fonction renvoie un char ** de la string.
 * @param map La string.
 * @param sep Le séparateur qui marque le début d'une nouvelle ligne.
*/
char **str_to_array(char *map, char sep)
{
    char **result = malloc(sizeof(char *) * (my_strlen(map) + 1));
    int column = 0;
    int li = 0;

    for (int index = 0; map[index] != '\0'; index++) {
        result[li] = malloc(sizeof(char) * (str_len_to(map, index, sep) + 1));
        for (; map[index] != sep && map[index] != '\0'; index++) {
            result[li][column] = map[index];
            column++;
        }
        result[li][column] = '\0';
        li++;
        column = 0;
        if (map[index] == '\0')
            break;
    }
    result[li] = NULL;
    return result;
}
