/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** str_sep_str.c
*/

#include "../my.h"

/***
 * Cette fonction concatène deux chaines de caractères et interpose un
 * caractère entr eles deux.
 * @param src La première string.
 * @param se La seconde string.
 * @param separator Le caractère entre les deux.
*/
char *char_sep_char(char *src, char *se, char separator)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + my_strlen(se) + 2));
    int index = 0;
    bool first = false;

    for (int i = 0; src[i] != '\0'; i++) {
        result[index] = src[i];
        index++;
    }
    result[index] = separator;
    index++;
    for (int i = 0; se[i] != '\0'; i++) {
        result[index] = se[i];
        index++;
    }
    result[index] = '\0';
    return result;
}
