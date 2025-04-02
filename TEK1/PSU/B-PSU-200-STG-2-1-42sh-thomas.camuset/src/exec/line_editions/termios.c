/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** termios
*/

#include "../../../include/shell.h"

void disable_raw_mode(void)
{
    old_termios.c_lflag &= ~(ICANON);
    old_termios.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_termios);
}

void enable_raw_mode(void)
{
    struct termios raw_termios;

    tcgetattr(STDIN_FILENO, &old_termios);
    atexit(disable_raw_mode);
    raw_termios = old_termios;
    raw_termios.c_cc[VMIN] = 1;
    raw_termios.c_cc[VTIME] = 0;
    raw_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_termios);
}
