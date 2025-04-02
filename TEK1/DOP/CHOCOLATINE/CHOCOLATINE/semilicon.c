/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** semilicon.c
*/

#include "my.h"

int execute_semilicon(char *str, infos_t *infos)
{
    char **table = str_to_array(str, ';');
    int exit_code;

    for (int i = 0; table[i] != NULL; i++) {
        table[i] = format_str(table[i], false);
        if (char_searcher(str, '|')) {
            exit_code = execute_with_pipe(table[i], infos);
        } else {
            exit_code = which_commands(table[i], infos, NULL);
        }
    }
    return exit_code;
}
