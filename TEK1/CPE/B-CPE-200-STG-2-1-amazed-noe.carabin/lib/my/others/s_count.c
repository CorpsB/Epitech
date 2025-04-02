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

static void skip_word2(char *str, char c, char c2, int *i)
{
    for (; str[*i] != c && str[*i] != c2 &&
    str[*i + 1] != '\0' && str[*i + 1] != '#'; ++(*i));
}

int s_count_double(char *str, char c, char c2)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '#'; ++i){
        if (str[i] != c && str[i] != c2){
            ++cpt;
            skip_word2(str, c, c2, &i);
        }
    }
    return cpt;
}
