/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-thibaut.louis
** File description:
** clean_str.c
*/

#include "../../my.h"

int skip(char *str, int i, char sep1, char sep2)
{
    for (; str[i + 1] != '\0' && str[i] != sep1 && str[i] != sep2; i++);
    return i;
}

char *clean_str(char *str, char sep1, char sep2)
{
    char *result = my_strdup("");
    int i_min;
    char *tmp;
    char tmp2[] = "  \0";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != sep1 && str[i] != sep2) {
            i_min = i;
            i = skip(str, i, sep1, sep2);
            tmp = my_substr(str, i, i_min);
            result = my_str_cat(result, tmp, ' ');
            free(tmp);
        }
    }
    tmp = my_substr(result, my_strlen(result), 1);
    tmp2[0] = str[my_strlen(str) - 1];
    tmp = my_str_cat2(tmp, tmp2);
    free(result);
    return tmp;
}
