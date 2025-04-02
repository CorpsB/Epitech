/*
** EPITECH PROJECT, 2024
** KJ_COUNT_CARAC
** File description:
** Counts the occurence of a given char.
*/

#include "../../../include/base/my.h"

static void skip_word(char *str, char c1, char c2, int *i)
{
    for (; str[*i] != c1 && str[*i] != c2 && str[*i + 1] != '\0'; ++(*i));
}

int s_count(char *str, char c1, char c2)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] != c1 && str[i] != c2){
            ++cpt;
            skip_word(str, c1, c2, &i);
        }
    }
    return cpt;
}
