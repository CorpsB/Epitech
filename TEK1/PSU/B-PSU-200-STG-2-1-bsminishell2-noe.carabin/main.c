/*
** EPITECH PROJECT, 2023
** BS_minishell2
** File description:
** main.c
*/

#include "my.h"

int execute_second(char **av, char **env, int *pipefd)
{
    int status;
    int pid;
    char **command2;
    int result;

    command2 = str_to_array(av[1], ' ');
    pid = fork();
    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execve(command2[0], command2, env);
        exit(EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
    close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd[2]);
    if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
        return 84;
    return 0;
}

int execute_first(char **av, char **env)
{
    int status;
    int pipefd[2];
    int pid;
    char **command1;

    command1 = str_to_array(av[2], ' ');
    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execve(command1[0], command1, env);
        exit(EXIT_FAILURE);
    }
    execute_second(av, env, pipefd);
    wait(&status);
    if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
        return 84;
}

int main(int ac, char **av, char **env)
{
    if (ac != 3)
        return 84;
    return execute_first(av, env);
}
