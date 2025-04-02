/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** is_exec.c
*/

#include "my.h"

int segv_func(int status)
{
    int signal = WTERMSIG(status);

    if (signal == SIGABRT)
        my_error("Abort");
    if (signal == SIGBUS)
        my_error("Bus error");
    if (signal == SIGFPE)
        my_error("Floating exception");
    if (signal == SIGSEGV)
        my_error("Segmentation fault");
    if (WCOREDUMP(status))
        my_error(" (core dumped)");
    my_error("\n");
    return signal + 128;
}

bool is_exec_func(char **command)
{
    for (int i = 0; command[0][i] != '\0'; i++)
        if (command[0][i] == '/')
            return true;
    return false;
}
