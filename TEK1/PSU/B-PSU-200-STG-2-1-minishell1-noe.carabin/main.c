/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** main.c
*/

#include "my.h"

static int execve_command(char **command, char *str, char **env)
{
    int id = fork();
    int status;

    if (id > 0){
        waitpid(id, &status, 0);
        if (WIFEXITED(status))
            return (WEXITSTATUS(status));
        if (WIFSIGNALED(status))
            return segv_func(status);
    } else {
        if (is_a_dir(str))
            exit(message(1, 2, 2, command[0], ": Permission denied.\n"));
        if (access(str, X_OK) != 0)
            exit(message(1, 2, 2, command[0], ": Command not found.\n"));
        execve(str, command, env);
        exit(EXIT_FAILURE);
    }
}

static int exec_command(char **env, char **command, linked_t *list)
{
    linked_t *tmp = list;
    char *cmd_path;
    char **emplacement = NULL;
    int exit_code = -1;
    int id = 0;

    id = search_from_list(tmp, "PATH");
    for (; tmp->id != id; tmp = tmp->next);
    emplacement = str_to_array(tmp->value, ':');
    for (int i = 0; emplacement[i] != NULL; i++){
        cmd_path = my_strstr(emplacement[i], command[0], '/');
        if (access(cmd_path, R_OK | F_OK | X_OK) != -1)
            exit_code = execve_command(command, cmd_path, env);
        free(cmd_path);
    }
    if (exit_code == -1)
        exit_code = message(1, 2, 2, command[0], ": Command not found.\n");
    if (emplacement != NULL)
        free_table(emplacement);
    return exit_code;
}

int run_command(char **command, infos_t *infos)
{
    bool is_exec = is_exec_func(command);
    int exit_code = 0;

    if (!is_exec)
        exit_code = exec_command(infos->env, command, infos->env_l);
    if (is_exec)
        exit_code = execve_command(command, command[0], infos->env);
    return exit_code;
}

static int get_nbr(char *str)
{
    int result = 0;

    if (str == NULL)
        return 0;
    result = str[0] - 48;
    for (int i = 1; str[i] != '\0'; i++) {
        result *= 10;
        result += (str[i] - 48);
    }
    return result;
}

static int search_exit_error(char **command)
{
    bool error = false;

    if (table_len(command) > 2 ||
    (command[1][0] < '0' || command[1][0] > '9')) {
        my_error("exit: Expression Syntax.\n");
        return -1;
    }
    for (int i = 0; command[1][i] != '\0'; i++)
        if (command[1][i] < '0' || command[1][i] > '9')
            error = true;
    if (error) {
        my_error("exit: Badly formed number.\n");
        return -1;
    }
    return get_nbr(command[1]);
}

int exit_shell(infos_t *infos, char **command)
{
    int nbr = 0;

    if (table_len(command) == 1) {
        infos->error = 2;
        return (0);
    }
    nbr = search_exit_error(command);
    if (nbr == -1)
        return 1;
    infos->error = 2;
    return nbr;
}

int which_commands(char *str, infos_t *infos)
{
    char **command = NULL;
    int exit_code = -1;

    if (str[0] == '\0')
        return 0;
    command = str_to_array(str, ' ');
    if (my_strcmp("env", command[0]) == 1)
        exit_code = show_env(infos->env_l, command);
    if (my_strcmp("cd", command[0]) == 1)
        exit_code = change_directory(&infos->env_l, command);
    if (my_strcmp("setenv", command[0]) == 1)
        exit_code = set_environement(command, &infos->env_l);
    if (my_strcmp("unsetenv", command[0]) == 1)
        exit_code = remove_env(&infos->env_l, command);
    if (my_strcmp("exit", command[0]) == 1)
        exit_code = exit_shell(infos, command);
    if (exit_code == -1)
        exit_code = run_command(command, infos);
    free_table(command);
    return exit_code;
}

int run_shell(infos_t *infos)
{
    char *str = NULL;
    char *clean_str;
    size_t size = 0;
    int nbr = 0;
    int exit_code = 0;

    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
    nbr = getline(&str, &size, stdin);
    if (nbr == -1)
        infos->error = 1;
    if (nbr == -1 || nbr == 1) {
        free(str);
        return 0;
    }
    clean_str = format_str(str);
    exit_code = which_commands(clean_str, infos);
    free(clean_str);
    return exit_code;
}

static int core(infos_t *infos)
{
    int exit_code = 0;
    int exit_tmp;

    while (infos->error == 0) {
        exit_tmp = run_shell(infos);
        if (infos->error != 1)
            exit_code = exit_tmp;
    }
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    return exit_code;
}

int main(int ac, char **av, char **env)
{
    int exit_code = 0;
    infos_t infos;

    if (ac != 1)
        return 84;
    infos.env_l = NULL;
    infos.error = 0;
    infos.env = NULL;
    re_build_env(env, &infos.env_l);
    change_env(&infos.env, infos.env_l, '=');
    exit_code = core(&infos);
    free_table(infos.env);
    return exit_code;
}
