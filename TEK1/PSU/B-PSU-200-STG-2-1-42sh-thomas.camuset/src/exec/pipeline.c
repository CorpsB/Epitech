/*
** EPITECH PROJECT, 2024
** RUN_PIPE
** File description:
** Run pipe command.
*/

#include "../../include/shell.h"

static void copy_fd(int src[2], int dest[2])
{
    dest[0] = src[0];
    dest[1] = src[1];
}

static void close_pipe(int fd[2])
{
    close(fd[0]);
    close(fd[1]);
}

static void redirect_pipe(int size, int i, int fd[2][2])
{
    if (i > 0){
        close(fd[0][1]);
        dup2(fd[0][0], STDIN_FILENO);
        close(fd[0][0]);
    }
    if (i < size - 1){
        close(fd[1][0]);
        dup2(fd[1][1], STDOUT_FILENO);
        close(fd[1][1]);
    }
}

int exec_pipeline(storage_bag_t *storage, pipe_data_t *data, int size)
{
    int fd[2][2];
    int status;
    int pid;

    for (int i = 0; i < size; ++i){
        pipe(fd[1]);
        pid = fork();
        if (pid == 0){
            redirect_pipe(size, i, fd);
            exit(exec_chevron(storage, data));
        }
        if (i > 0)
            close_pipe(fd[0]);
        copy_fd(fd[1], fd[0]);
        for (int i = 0; i < 1e7; ++i);
        data = data->next;
    }
    close_pipe(fd[0]);
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}
