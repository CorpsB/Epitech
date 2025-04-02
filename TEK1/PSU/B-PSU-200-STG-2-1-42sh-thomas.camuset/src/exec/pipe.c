/*
** EPITECH PROJECT, 2024
** EXEC_PIPE
** File description:
** Run commands who are not implemeted.
*/

#include "../../include/shell.h"

int exec_pipe(storage_bag_t *storage, char **cmd_line, char *data)
{
    int fd[2];
    int status;
    int pid;

    pipe(fd);
    pid = fork();
    if (pid == 0){
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        exit(run_subcommand(storage, cmd_line));
    }
    close(fd[0]);
    my_putstr(data, fd[1]);
    my_putchar('\n', fd[1]);
    close(fd[1]);
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}

int exec_42sh_p_pipe(storage_bag_t *storage, char **tab, char *data)
{
    int fd[2];
    int status;
    int pid;

    pipe(fd);
    pid = fork();
    if (pid == 0){
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        exit(exec_path(storage->env, tab, storage->path_to_42sh));
    }
    close(fd[0]);
    my_putstr(data, fd[1]);
    my_putchar('\n', fd[1]);
    close(fd[1]);
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}

static char *exec_42sh_clean_result(char *str)
{
    char *result = my_origin_strtok(str, "\n");

    free(str);
    return result;
}

static void exec_42sh_child(storage_bag_t *storage, char **tab, int fd[2][2])
{
    close(fd[0][1]);
    close(fd[1][0]);
    dup2(fd[0][0], STDIN_FILENO);
    close(fd[0][0]);
    dup2(fd[1][1], STDOUT_FILENO);
    close(fd[1][1]);
    exit(exec_path(storage->env, tab, "./42sh"));
}

char *exec_42sh(storage_bag_t *storage, char *data, char **tab)
{
    int fd[2][2];
    char *result;
    int status;
    int pid;

    pipe(fd[0]);
    pipe(fd[1]);
    pid = fork();
    if (pid == 0)
        exec_42sh_child(storage, tab, fd);
    close(fd[0][0]);
    close(fd[1][1]);
    my_putstr(data, fd[0][1]);
    my_putchar('\n', fd[0][1]);
    close(fd[0][1]);
    waitpid(pid, &status, 0);
    result = my_readfd(fd[1][0]);
    close(fd[1][0]);
    return exec_42sh_clean_result(result);
}
