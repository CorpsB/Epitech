/*
** EPITECH PROJECT, 2024
** KJ_CHAR_COUNTER
** File description:
** Counts the char content.
*/

#include "../../../include/my.h"

static void skip_word(char *str, char c, int *i)
{
    for (; str[*i] != c && str[*i + 1] != '\0'; ++(*i));
}

int s_count(char *str, char c)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] != c){
            ++cpt;
            skip_word(str, c, &i);
        }
    }
    return cpt;
}
