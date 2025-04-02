/*
** EPITECH PROJECT, 2024
** EXEC
** File description:
** Exec things.
*/

#include "../include/project.h"

void send_move(char *move, char *value)
{
    char *str = NULL;
    size_t size = 0;

    my_putstr(move, 1);
    my_putchar(':', 1);
    my_putstr(value, 1);
    my_putchar('\n', 1);
    getline(&str, &size, stdin);
    free(str);
}

float send_get_move(char *move)
{
    char *str = NULL;
    size_t size = 0;
    char **table;

    my_putstr(move, 1);
    getline(&str, &size, stdin);
    table = a_convert_s(str, ':');
    free(str);
    a_free(table);
    return atof(table[3]);
}

void get_infos(direction_t *dir)
{
    char *str = NULL;
    size_t nbr = 0;
    char **infos;

    my_putstr("GET_INFO_LIDAR\n", 1);
    getline(&str, &nbr, stdin);
    infos = a_convert_s(str, ':');
    dir->left = atoi(infos[3]);
    dir->forward = get_average(infos, 16, 17);
    dir->right = atoi(infos[34]);
    a_free(infos);
    free(str);
}
