/*
** EPITECH PROJECT, 2024
** EXEC_UNBUILTIN
** File description:
** Run commands who are not implemeted.
*/

#include "../../../include/shell.h"

static int is_accessible(char *bin_path)
{
    struct stat sa;
    int gate = stat(bin_path, &sa);

    if (gate == -1)
        return msg(ERR, 2, 2, bin_path, ": Command not found.\n");
    if (!S_ISREG(sa.st_mode) || access(bin_path, F_OK | X_OK | R_OK) == -1)
        return msg(ERR, 2, 2, bin_path, ": Permission denied.\n");
    return 0;
}

int exit_signal(int status)
{
    int signal = WTERMSIG(status);
    int exit_code = -1;

    if (signal == SIGSEGV)
        exit_code = msg(ERR, 2, 1, "Segmentation fault");
    if (signal == SIGFPE)
        exit_code = msg(ERR, 2, 1, "Floating exception");
    if (signal == SIGBUS)
        exit_code = msg(ERR, 2, 1, "Bus error");
    if (signal == SIGABRT)
        exit_code = msg(ERR, 2, 1, "Abort");
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)", 2);
    my_putchar('\n', 2);
    return 128 + signal;
}

static int get_execution_error(char *bin_path)
{
    my_putstr(bin_path, 2);
    switch (errno){
        case ENOEXEC:
            my_putstr(": Exec format error. Wrong Architecture.\n", 2);
            break;
        case ELIBBAD:
            my_putstr(": Exec format error. Wrong Architecture.\n", 2);
            break;
        default:
            perror("execve");
            break;
    }
    return 126;
}

int exec_path(char **env, char **data, char *bin_path)
{
    int exit_code;
    int status;
    int pid;

    if (is_accessible(bin_path) == ERR)
        return ERR;
    pid = fork();
    if (pid == 0){
        execve(bin_path, data, env);
        exit(get_execution_error(bin_path));
    }
    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)){
        exit_code = exit_signal(status);
        if (exit_code != -1)
            return exit_code;
    }
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
}

int exec_unbuiltin(storage_bag_t *storage, char **data)
{
    int exit_code;
    char *bin_path;

    if (access(data[0], F_OK) != -1)
        bin_path = my_strdup(data[0]);
    else
        bin_path = path_retriever(data[0], storage->pathlist);
    if (bin_path == NULL)
        return msg(ERR, 2, 2, data[0], ": Command not found.\n");
    exit_code = exec_path(storage->env, data, bin_path);
    free(bin_path);
    return exit_code;
}
