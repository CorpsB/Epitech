/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** file_checker.c
*/

#include "my.h"

static char *error_case(char *map)
{
    int p = 0;
    int x = 0;
    int o = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != ' ' && map[i] != '#' && map[i] != 'X' && map[i] != 'O' &&
        map[i] != 'P' && map[i] != '\n' && map[i] != '\0')
            return "Error";
        if (map[i] == 'X')
            x++;
        if (map[i] == 'O')
            o++;
        if (map[i] == 'P')
            p++;
    }
    if (p != 1 || x != o)
        return "Error";
    return map;
}

char *file_checker(char *filepath)
{
    char *map;
    int open_value = open(filepath, O_RDONLY);
    struct stat infos;

    if (open_value == -1)
        return "Error";
    stat(filepath, &infos);
    map = malloc(sizeof(char) * (infos.st_size + 1));
    read(open_value, map, infos.st_size);
    map[infos.st_size] = '\0';
    close(open_value);
    return error_case(map);
}
