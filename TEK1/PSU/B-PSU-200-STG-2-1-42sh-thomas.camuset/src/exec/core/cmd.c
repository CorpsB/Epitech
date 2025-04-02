/*
** EPITECH PROJECT, 2024
** RUN_SUBCMD
** File description:
** Run sub command.
*/

#include "../../../include/shell.h"

int is_subcommand(char **cmd)
{
    if (my_strncmp(cmd[0], "cd", 2) == 0)
        return 1;
    if (my_strncmp(cmd[0], "exit", 4) == 0)
        return 1;
    if (my_strncmp(cmd[0], "unsetenv", 8) == 0)
        return 1;
    if (my_strncmp(cmd[0], "setenv", 6) == 0 && a_size(cmd) != 1)
        return 1;
    if (my_strncmp(cmd[0], "alias", 5) == 0 && a_size(cmd) != 1)
        return 1;
    if (my_strncmp(cmd[0], "unalias", 7) == 0)
        return 1;
    if (my_strncmp(cmd[0], "set", 3) == 0 && a_size(cmd) != 1)
        return 1;
    if (my_strncmp(cmd[0], "unset", 5) == 0)
        return 1;
    return 0;
}

static int run_subcommand_next(storage_bag_t *storage, char **cmd,
    int exit_code)
{
    if (my_strcmp(cmd[0], "history") == 0)
        exit_code = disp_history(storage, cmd);
    if (cmd[0][0] == '!')
        exit_code = excl_history(storage, cmd, true);
    if (my_strcmp("set", cmd[0]) == 0 && a_size(cmd) == 1) {
        l_display_var(storage->set);
        exit_code = 0;
    }
    if (my_strcmp("set", cmd[0]) == 0 && a_size(cmd) != 1)
        exit_code = set(storage, cmd);
    if (my_strcmp("unset", cmd[0]) == 0)
        exit_code = unset(storage, cmd);
    if (my_strcmp("alias", cmd[0]) == 0)
        exit_code = alias(storage, cmd);
    if (my_strcmp("unalias", cmd[0]) == 0)
        exit_code = unalias(storage, cmd);
    return exit_code;
}

int run_subcommand(storage_bag_t *storage, char **cmd)
{
    int exit_code = -1;

    if (cmd == NULL)
        return 0;
    exit_code = redirect_alias_test_loop(storage, cmd[0]);
    if (my_strcmp(cmd[0], "cd") == 0)
        exit_code = change_directory(storage, cmd);
    if (my_strcmp(cmd[0], "env") == 0 || my_strcmp(cmd[0], "printenv") == 0)
        exit_code = display_env(storage, cmd);
    if (my_strcmp(cmd[0], "setenv") == 0)
        exit_code = set_env(storage, cmd);
    if (my_strcmp(cmd[0], "unsetenv") == 0)
        exit_code = unset_env(storage, cmd);
    if (my_strcmp(cmd[0], "exit") == 0)
        exit_code = exit_prompt(storage, cmd);
    exit_code = run_subcommand_next(storage, cmd, exit_code);
    if (exit_code == -1)
        exit_code = exec_unbuiltin(storage, cmd);
    return exit_code;
}

int run_pipe_command(storage_bag_t *storage, pipe_data_t *data)
{
    int size = l_pipe_size(data);
    int exit_code;

    if (size == 0)
        return 0;
    if (is_subcommand(data->build_cmd) && !data->instance){
        exit_code = exec_chevron(storage, data);
        l_pipe_free(&data);
        return exit_code;
    }
    l_pipe_reverse(&data);
    exit_code = exec_pipeline(storage, data, size);
    l_pipe_free(&data);
    return exit_code;
}

int run_command(storage_bag_t *storage, char *str)
{
    int exit_code;
    cmd_data_t *line = NULL;

    if (count_guillemet(str) == ERR || count_backticks(str) == ERR)
        return ERR;
    if (parse_data(&line, str, storage) == ERR){
        l_cmd_free(&line);
        return ERR;
    }
    exit_code = parse_semicolon(storage, line);
    return exit_code;
}
