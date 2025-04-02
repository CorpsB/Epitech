/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** bad_archi.c
*/

#include "my.h"

int bad_architecture(int exit, char **command)
{
    if (errno == ENOEXEC) {
        my_putstr(command[0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        return 126;
    } else {
        return exit;
    }
}
