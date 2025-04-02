/*
** EPITECH PROJECT, 2023
** New-project
** File description:
** two_word_array.c
*/

#include "my.h"
#include <string.h>

int str_len_to(char *str, int index, char separator)
{
    int a = index;

    for (; str[index] != '\0' && str[index] != separator; index++);
    return (index - a);
}

char **str_to_array(char *map, char sep)
{
    char **result = malloc(sizeof(char *) * (my_strlen(map) + 1));
    int column = 0;
    int li = 0;

    for (int index = 0; map[index] != '\0'; index++) {
        result[li] = malloc(sizeof(char) * (str_len_to(map, index, sep) + 1));
        for (; map[index] != sep && map[index] != '\0'; index++) {
            result[li][column] = map[index];
            column++;
        }
        result[li][column] = '\0';
        li++;
        column = 0;
        if (map[index] == '\0')
            break;
    }
    result[li] = NULL;
    return result;
}

char *my_strstr(char *src, char *se, char separator)
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

char *write_withoutlast(char *str, bool need)
{
    char *result = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    if (!need) {
        free(result);
        return str;
    }
    for (; str[i + 1] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    free(str);
    return result;
}

int table_len(char **table)
{
    int i = 0;

    for (; table[i] != NULL; i++);
    return i;
}
