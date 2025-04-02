/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** title.c
*/

#include "../../../include/project.h"
#include "../../graphical.h"

static void before(int before, WINDOW *win)
{
    for (int i = 0; i < before; i++)
        wprintw(win, " ");
    return;
}

char ***init_title(void)
{
    char ***title = malloc(sizeof(char **) * (8));

    title[0] = letter_c();
    title[1] = letter_o();
    title[2] = letter_r();
    title[3] = letter_e();
    title[4] = letter_w();
    title[5] = letter_a();
    title[6] = letter_r();
    title[7] = NULL;
    return title;
}

static void print_space(WINDOW *win, int i)
{
    if (i != 6)
        wprintw(win, "  ");
    return;
}

void print_title(int size, WINDOW *win, char ***title)
{
    int space = 0;

    wprintw(win, "\n");
    for (int j = 0; j < 5; j++) {
        before(size, win);
        for (int i = 0; i < 7; i++) {
            wprintw(win, "%s", title[i][j]);
            print_space(win, i);
        }
        wprintw(win, "\n");
    }
}
