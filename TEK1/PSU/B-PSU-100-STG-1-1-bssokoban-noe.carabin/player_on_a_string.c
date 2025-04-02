/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-noe.carabin
** File description:
** player_on_a_string.c
*/

#include <curses.h>
#include <unistd.h>

int main(void)
{
    int line = 0;
    int column = 0;
    int key = 0;
    char str[24] = "|.....................|\0";
    int P_co = 10;

    initscr();
    for (; key != 32;) {
        getmaxyx(stdscr, line, column);
        str[P_co] = 'P';
        mvprintw(line / 2, column / 2, str);
        str[P_co] = '.';
        refresh();
        key = getch();
        P_co = change_value(str, P_co, key);
        clear();
    }
    endwin();
    return 0;
}

int change_value(char *str, int P_co, int key)
{
    if (key == 'z' && str[P_co + 1] != '|') {
            P_co = P_co + 1;
        }
        if (key == 'a' && str[P_co - 1] != '|') {
            P_co = P_co - 1;
    }
    return (P_co);
}
