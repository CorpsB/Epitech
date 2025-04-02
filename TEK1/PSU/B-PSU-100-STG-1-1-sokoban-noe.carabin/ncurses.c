/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** ncurses.c
*/

#include "my.h"

void static display(char **map, linked_t *infos)
{
    linked_t *tmp = infos;

    for (; tmp != NULL; tmp = tmp->next) {
        map[tmp->line][tmp->column] = tmp->type;
    }
    for (int i = 0; map[i] != NULL; i++) {
        printw("%s\n", map[i]);
    }
}

static bool is_win_next(char **map, int column, int line)
{
    if (map[column][line] == 'O')
        return false;
    return true;
}

static bool is_win_f(char **map, linked_t *infos)
{
    linked_t *player = infos;
    bool is_win = true;

    for (; player != NULL && player->type != 'P'; player = player->next);
    for (linked_t *checker = infos; checker != NULL; checker = checker->next) {
        if (checker->type == 'O' && checker->column == player->column &&
        checker->line == player->column)
            return false;
    }
    for (int line = 0; map[line] != NULL; line++) {
        for (int column = 0; map[line][column] != '\0' && is_win; column++) {
            is_win = is_win_next(map, column, line);
        }
    }
    return is_win;
}

static void change(char **map, linked_t *infos, int ch)
{
    linked_t *tmp = infos;

    if (ch != KEY_UP && ch != KEY_DOWN && ch != KEY_LEFT && ch != KEY_RIGHT)
        return;
    for (; tmp != NULL && tmp->type != 'P'; tmp = tmp->next);
    if (ch == KEY_UP)
        top_moov(tmp, infos, map);
    if (ch == KEY_DOWN)
        botom_moov(tmp, infos, map);
    if (ch == KEY_LEFT)
        left_moov(tmp, infos, map);
    if (ch == KEY_RIGHT)
        right_moov(tmp, infos, map);
}

bool core(char **map, linked_t *infos)
{
    bool reset = false;
    int ch = 0;
    WINDOW *bob = initscr();

    keypad(bob, true);
    display(map, infos);
    for (bool is_win = false; !is_win && !reset;
    is_win = is_win_f(map, infos)) {
        ch = getch();
        if (ch == 32)
            reset = true;
        change(map, infos, ch);
        clear();
        display(map, infos);
        refresh();
    }
    endwin();
    return reset;
}

// is_win = is_win_f(map, infos)) {
//     if (!is_larger(map))
//         continue;
//     ch = getch();
