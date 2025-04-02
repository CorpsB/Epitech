/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** env.c
*/

#include "my.h"

int show_env(linked_t *env_l, char **command)
{
    if (table_len(command) != 1)
        return message(1, 2, 3, "env: '", command[1],
        "': No such file or directory.");
    my_show_revlist(env_l);
    return 0;
}
