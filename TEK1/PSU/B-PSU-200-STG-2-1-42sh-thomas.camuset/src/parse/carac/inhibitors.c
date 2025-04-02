/*
** EPITECH PROJECT, 2024
** INHIBITORS
** File description:
** Things that ignore parsing.
*/

#include "../../../include/shell.h"

static int is_next_guillemet(char *str, char c, int i)
{
    ++i;
    for (; str[i] != c && str[i] != '\0'; ++i);
    if (str[i] == c)
        return i;
    return -1;
}

int count_guillemet(char *str)
{
    int tmp = 0;
    int cpt1 = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == '"')
            tmp = is_next_guillemet(str, '"', i);
        if (tmp == -1)
            return msg(ERR, 2, 1, "Unmatched '\"'.\n");
        if (str[i] == '"'){
            i = tmp;
            continue;
        }
        if (str[i] == '\'' && cpt1 % 2 == 0 &&
        is_next_guillemet(str, '\'', i) == -1)
            return msg(ERR, 2, 1, "Unmatched '''.\n");
        if (str[i] == '\'')
            ++cpt1;
    }
    return 0;
}

int count_backticks(char *str)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '`')
            ++cpt;
    if (cpt % 2 == 0)
        return 0;
    return msg(ERR, 2, 1, "Unmatched '`'.\n");
}

int count_paranthesis(char *str)
{
    int p_open = 0;
    int p_close = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (str[i] == '(')
            ++p_open;
        if (str[i] == ')')
            ++p_close;
    }
    if (p_open == p_close)
        return 0;
    if (p_open > p_close)
        return msg(ERR, 2, 1, "Too many ('s.\n");
    return msg(ERR, 2, 1, "Too many )'s.\n");
}
