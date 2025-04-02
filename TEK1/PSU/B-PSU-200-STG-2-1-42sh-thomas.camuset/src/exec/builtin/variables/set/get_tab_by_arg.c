/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** set_fun.c
*/

#include "../../../../../include/shell.h"

static int skip_word(char *str, char sep, int i)
{
    for (; str[i] != '\0' && str[i] != sep && str[i] != ' '; ++i);
    return i - 1;
}

static int count_word(char *str, char sep)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == sep){
            ++cpt;
            continue;
        }
        if (str[i] != ' '){
            ++cpt;
            i = skip_word(str, sep, i);
        }
    }
    return cpt;
}

char **get_tab_by_arg(char *str, char *sep)
{
    char **res = malloc(sizeof(char *) * (count_word(str, sep[0]) + 1));
    int cpt = 0;
    int j;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == sep[0]){
            res[cpt] = my_strdup(sep);
            ++cpt;
            continue;
        }
        if (str[i] != ' '){
            j = i;
            i = skip_word(str, sep[0], i);
            res[cpt] = my_substr(str, j, i + 1);
            ++cpt;
        }
    }
    res[cpt] = NULL;
    return res;
}
