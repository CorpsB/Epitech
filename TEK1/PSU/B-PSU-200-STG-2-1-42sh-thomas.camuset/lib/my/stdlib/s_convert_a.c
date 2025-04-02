/*
** EPITECH PROJECT, 2024
** MY_STR_TO_WORD_ARRAY
** File description:
** Transform a string into an array.
*/

#include "../../../include/shell.h"

char *s_convert_a(char **array, int i)
{
    char *res = my_strdup("");

    for (; array[i] != NULL; ++i)
        res = s_sependmerge(res, array[i], ' ');
    res[my_strlen(res) - 1] = '\0';
    return res;
}
