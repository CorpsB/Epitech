/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** operator.c
*/

#include "my.h"

bool char_searcher(char *str, char search)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != search)
            continue;
        return true;
    }
    return false;
}

int which_operator(char *str, infos_t *list)
{
    int exit_code = 0;

    if (char_searcher(str, '|'))
        exit_code += exec_with_pipe(str, list);
    return exit_code;
}
