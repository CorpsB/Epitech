/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** red_searcher.c
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

bool search_enter_redirection(char **table)
{
    bool result = false;

    for (int i = 0; table[i] != NULL; i++) {
        result = char_searcher(table[i], '<');
        if (result)
            return true;
    }
    return false;
}

bool search_exit_redirection(char **table)
{
    bool result = false;

    for (int i = 0; table[i] != NULL; i++) {
        result = char_searcher(table[i], '>');
        if (result)
            return true;
    }
    return false;
}
