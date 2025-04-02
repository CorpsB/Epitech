/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** mooving.c
*/

#include "my.h"

void top_moov(linked_t *tmp, linked_t *infos, char **map)
{
    if (map[tmp->line - 1][tmp->column] == '#' ||
    (map[tmp->line - 1][tmp->column] == 'X' &&
    map[tmp->line - 2][tmp->column] == '#'))
        return;
    map[tmp->line][tmp->column] = ' ';
    tmp->line--;
    for (linked_t *second = infos; second != NULL; second = second->next) {
        if (second->type == 'X' && tmp->line == second->line &&
        tmp->column == second->column)
            second->line--;
    }
    return;
}

void botom_moov(linked_t *tmp, linked_t *infos, char **map)
{
    if (map[tmp->line + 1][tmp->column] == '#' ||
    (map[tmp->line + 1][tmp->column] == 'X' &&
    map[tmp->line + 2][tmp->column] == '#'))
        return;
    map[tmp->line][tmp->column] = ' ';
    tmp->line++;
    for (linked_t *second = infos; second != NULL; second = second->next) {
        if (second->type == 'X' && tmp->line == second->line &&
        tmp->column == second->column)
            second->line++;
    }
}

void left_moov(linked_t *tmp, linked_t *infos, char **map)
{
    if (map[tmp->line][tmp->column- 1] == '#' ||
    (map[tmp->line][tmp->column - 1] == 'X' &&
    map[tmp->line][tmp->column - 2] == '#'))
        return;
    map[tmp->line][tmp->column] = ' ';
    tmp->column--;
    for (linked_t *second = infos; second != NULL; second = second->next) {
        if (second->type == 'X' && tmp->line == second->line &&
        tmp->column == second->column)
            second->column--;
    }
}

void right_moov(linked_t *tmp, linked_t *infos, char **map)
{
    if (map[tmp->line][tmp->column + 1] == '#' ||
    (map[tmp->line][tmp->column + 1] == 'X' &&
    map[tmp->line][tmp->column + 2] == '#'))
        return;
    map[tmp->line][tmp->column] = ' ';
    tmp->column++;
    for (linked_t *second = infos; second != NULL; second = second->next) {
        if (second->type == 'X' && tmp->line == second->line &&
        tmp->column == second->column)
            second->column++;
    }
}
