/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** arena.c
*/

#include "../../include/project.h"
#include "../graphical.h"

static int define_pc_colour(WINDOW *win, char descriptor)
{
    int colour = descriptor - 44;

    init_pair(5, COLOR_RED, COLOR_WHITE);
    init_pair(6, COLOR_GREEN, COLOR_WHITE);
    init_pair(7, COLOR_CYAN, COLOR_WHITE);
    init_pair(8, COLOR_MAGENTA, COLOR_WHITE);
    wattron(win, COLOR_PAIR(colour));
    return colour;
}

static int define_colour(WINDOW *win, char descriptor)
{
    int color = descriptor - 48;

    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    wattron(win, COLOR_PAIR(color));
    return color;
}

static bool is_pc(corewar_t *vm, int i)
{
    champions_t *tmp = vm->champions;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->pc == i && tmp->is_alive == true)
            return true;
    }
    return false;
}

void print_arena(WINDOW *win, corewar_t *vm)
{
    int j = 0;
    int colour = 0;

    for (int i = 0; vm->memory[i] != '\0'; i += 2) {
        if (!is_pc(vm, i))
            colour = define_colour(win, vm->mem_owner[j]);
        else
            colour = define_pc_colour(win, vm->mem_owner[j]);
        wprintw(win, "%c%c", vm->memory[i], vm->memory[i + 1]);
        wattroff(win, COLOR_PAIR(colour));
        if (i % LCHAR - 1 == 0 && i != 0)
            wprintw(win, "\n");
        else
            wprintw(win, " ");
        ++j;
    }
}
