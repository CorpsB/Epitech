/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-noe.carabin
** File description:
** bs.c
*/

#include <curses.h>
#include <unistd.h>


int main(void)
{
    int line = 0;
    int column = 0;
    int key = 0;

    initscr();
    for (; key != 32;) {
        getmaxyx(stdscr, line, column);
        mvprintw(line / 2, column / 2, "Hello World");
        refresh();
        key = getch();
        clear();
    }
    endwin();
    return 0;
}
