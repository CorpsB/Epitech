/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** informations_arrays.c
*/

#include "my.h"

static int str_len_to(char *str, int index, char separator)
{
    int a = index;

    for (; str[index] != '\0' && str[index] != separator; index++);
    return (index - a);
}

static char **str_to_array(char *map, char sep)
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

static void is_special_char(char **map, int line, int column,
    linked_t **infos_position)
{
    if (map[line][column] == 'X' || map[line][column] == 'O' ||
    map[line][column] == 'P') {
        my_put_in_list(infos_position, map[line][column], line, column);
        map[line][column] = ' ';
    }
    return;
}

static void get_info(char **map, linked_t **infos_position)
{
    int column = 0;
    int line = 0;

    for (; map[line] != NULL; line++) {
        for (; map[line][column] != '\0'; column++) {
            is_special_char(map, line, column, infos_position);
        }
        column = 0;
    }
    return;
}

char **get_informtion_array(char *pre_map, linked_t **infos_position)
{
    char **map;

    map = str_to_array(pre_map, '\n');
    get_info(map, infos_position);
    return map;
}
