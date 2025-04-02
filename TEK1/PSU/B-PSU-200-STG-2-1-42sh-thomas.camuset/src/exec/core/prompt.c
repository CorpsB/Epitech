/*
** EPITECH PROJECT, 2024
** COMMAND HANDLER
** File description:
** Run command.
*/

#include "../../../include/shell.h"

int exit_prompt(storage_bag_t *storage, char **cmd)
{
    int size = a_size(cmd);
    int exit_code = 0;

    if (size == 2){
        if (cmd[1][0] < '0' || cmd[1][0] > '9')
            return msg(ERR, 2, 1, "exit: Expression Syntax.\n");
        exit_code = n_convert_s(cmd[1]);
        if (my_strlen(cmd[1]) != n_size(exit_code))
            return msg(ERR, 2, 1, "exit: Badly formed number.\n");
    }
    if (size > 2)
        return msg(ERR, 2, 1, "exit: Expression Syntax.\n");
    storage->is_exit = 2;
    return exit_code;
}

void print_prompt_exit_code(storage_bag_t *storage, char *w_dir)
{
    int start = 0;

    if (storage->exit_code == 0)
        my_printf("\033[97m[\033[92m%d\033[0m\033[97m]",
        storage->exit_code);
    else
        my_printf("\033[97m[\033[31m%d\033[0m\033[97m]",
        storage->exit_code);
    if (my_strncmp(w_dir, "/home/", 6) == 0 &&
    my_strscmp(w_dir, storage->username, 6, my_strlen(storage->username)) == 0)
        start = 6 + my_strlen(storage->username);
    my_printf("\033[97m[\033[92m%s@%s\033[97m ", storage->username,
    storage->hostname);
    if (start != 0)
        my_putchar('~', 1);
    my_lim_putstr(w_dir, start);
    my_putstr("]$\033[0m ", 1);
}

int run_prompt_tty(storage_bag_t *storage)
{
    size_t size = 0;
    char *line = NULL;
    char w_dir[1000];
    int exit_code;
    int byte_read;

    getcwd(w_dir, 1000);
    byte_read = getline(&line, &size, stdin);
    if (byte_read == -1){
        storage->is_exit = 1;
        free(line);
        return 0;
    }
    line[my_strlen(line) - 1] = '\0';
    storage->exit_code = run_command(storage, line);
    free(line);
    return storage->exit_code;
}

int run_prompt(storage_bag_t *storage)
{
    int exit_code;

    storage->exit_code = run_command(storage, storage->prompt.command);
    free(storage->prompt.command);
    return storage->exit_code;
}
