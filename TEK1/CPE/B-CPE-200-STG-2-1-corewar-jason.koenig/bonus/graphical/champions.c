/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** champions.c
*/

#include "../../include/project.h"
#include "../graphical.h"

static void printer(char name[PROG_NAME_LENGTH + 1], WINDOW *win)
{
    int position = my_strlen(name);

    for (int i = 0; (i < (LCHAR * 1.5 - 1 - position) / 2); i++)
        wprintw(win, " ");
    wprintw(win, "%s\n", name);
}

void print_champions(corewar_t *vm, WINDOW *win)
{
    champions_t *tmp = vm->champions;

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    wprintw(win, "\n");
    for (int i = 1; i < 5; i++) {
        wprintw(win, "\n");
        for (; tmp != NULL && tmp->is_clone == true; tmp = tmp->next);
        if (tmp == NULL)
            continue;
        wattron(win, COLOR_PAIR(i));
        printer(tmp->data.prog_name, win);
        wattroff(win, COLOR_PAIR(i));
        tmp = tmp->next;
    }
    wprintw(win, "\n");
}
