/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** my_str_to_word_array_upgrade.c
*/

#include "../../my.h"

static int count_space(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t'){
            count++;
            skip(str, i, ' ', '\t');
        }
    }
    return count;
}

static char *get_word(char *str, int i, int i_min)
{
    if (str[i] == ' ' || str[i] == '\t')
        return my_substr(str, i, i_min);
    if (str[i + 1] == '\0')
        return my_substr(str, i + 1, i_min);
    return my_substr(str, i, i_min);
}

char **my_str_to_word_array_upgrade(char *str, char sep1, char sep2)
{
    char **result = malloc(sizeof(char *) * (count_space(str) + 2));
    int i_min;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            i_min = i;
            i = skip(str, i, sep1, sep2);
            result[j] = get_word(str, i, i_min);
            j++;
        }
    }
    result[j] = NULL;
    return result;
}
