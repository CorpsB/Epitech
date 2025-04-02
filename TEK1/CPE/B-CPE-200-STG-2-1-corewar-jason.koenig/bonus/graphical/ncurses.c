/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** ncurses.c
*/

#include "../../include/project.h"
#include "../graphical.h"

void graphical(corewar_t *vm, int cycle, WINDOW *win, char ***title)
{
    wclear(win);
    print_title((LCHAR * 1.5 - 46) / 2, win, title);
    print_cycle((LCHAR * 1.5 - 12) / 2, win, cycle);
    print_champions(vm, win);
    print_arena(win, vm);
    wrefresh(win);
    napms(10);
}
