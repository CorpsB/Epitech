/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** cycle.c
*/

#include "../../include/project.h"
#include "../graphical.h"

void print_cycle(int before, WINDOW *win, int cycle)
{
    wprintw(win, "\n");
    for (int i = 0; i < before; i++) {
        wprintw(win, " ");
    }
    wprintw(win, "CYCLE: %d\n", cycle);
}
