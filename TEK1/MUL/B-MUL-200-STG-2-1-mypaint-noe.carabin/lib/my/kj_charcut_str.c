/*
** EPITECH PROJECT, 2023
** KJ_CHARCUT_STR
** File description:
** COPY A STRING INTO AN OTHER ONE.
*/

#include "../../includes/my.h"

static int is_greater(int i_skip, int i_stop)
{
    if (i_skip > i_stop || i_skip < 0)
        return (0);
    return (1);
}

char *kj_charcut_str(char const *str, int i_start,
    int i_stop, int i_skip)
{
    char *res = malloc(sizeof(char) * (i_stop - i_start -
    is_greater(i_skip, i_stop) + 1));
    int i = i_start;
    int j = 0;
    int j_stop = i_stop - i_start - is_greater(i_skip, i_stop);

    while (i < i_stop){
        if (i != i_skip){
            res[j] = str[i];
            ++j;
        }
        ++i;
    }
    res[j_stop] = '\0';
    return (res);
}
