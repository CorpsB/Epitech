/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.carabin
** File description:
** pipe.c
*/

#include "my.h"

static void execute_with_pipe_next_next(int i, pipe_t *pipe_i)
{
    if (i != 0) {
        close(pipe_i->old_fd[0]);
        close(pipe_i->old_fd[1]);
    }
}

static int execute_with_pipe_next(char **table, infos_t *infos, pipe_t *pipe_i,
    int exit_code)
{
    int pid;
    int size = table_len(table);

    for (int i = 0; i < size; i++) {
        table[i] = format_str(table[i], false);
        pipe(pipe_i->fd);
        pid = fork();
        if (pid == 0) {
            search_execut_env(pipe_i, i, size, table);
            exit(which_commands(table[i], infos, pipe_i));
        }
        execute_with_pipe_next_next(i, pipe_i);
        pipe_i->old_fd[0] = pipe_i->fd[0];
        pipe_i->old_fd[1] = pipe_i->fd[1];
        for (int i = 0; i < 10000000; i++);
    }
    waitpid(pid, &exit_code, 0);
    return exit_code;
}

static bool pipe_error_next(char **table, int i, bool error)
{
    for (int j = 0; table[i][j] != '\0'; j++) {
        if (table[i][j] != ' ' && table[i][j] != '\t') {
            error = false;
        }
    }
    return error;
}

bool pipe_error(char **table)
{
    bool error;

    for (int i = 0; table[i] != NULL; i++)
        if (table[i][0] == '\0')
            return true;
    for (int i = 0; table[i] != NULL; i++) {
        error = true;
        error = pipe_error_next(table, i, error);
        if (error)
            return true;
    }
    return false;
}

int execute_with_pipe(char *clean_str, infos_t *infos)
{
    pipe_t pipe_info;
    pid_t pid;
    int exit_code;
    char **table = str_to_array(clean_str, '|');
    int size = table_len(table);

    if (pipe_error(table)) {
        my_putstr("Invalid null command.\n");
        return WEXITSTATUS(1);
    }
    exit_code = execute_with_pipe_next(table, infos, &pipe_info, exit_code);
    close(pipe_info.old_fd[0]);
    close(pipe_info.old_fd[1]);
    return WEXITSTATUS(exit_code);
}
