/*
** EPITECH PROJECT, 2024
** 42sh PROJECT
** File description:
** Version: RELEASE 3.0
*/

#include "../include/shell.h"

static void draw_cmd_advanced(cmd_data_t *tmp)
{
    if (tmp->TOKEN == COMMAND_TOKEN)
        my_printf(" %s", "COMMAND_TOKEN");
    if (tmp->TOKEN == PARENTHESE_START_TOKEN)
        my_printf(" %s", "PARENTHESE_START_TOKEN");
    if (tmp->TOKEN == PARENTHESE_END_TOKEN)
        my_printf(" %s", "PARENTHESE_END_TOKEN");
    if (tmp->TOKEN == EXTERNAL_PARENTHESE_TOKEN)
        my_printf(" %s", "EXTERNAL_PARENTHESE_TOKEN");
}

void draw_cmd(cmd_data_t *data)
{
    for (cmd_data_t *tmp = data; tmp != NULL; tmp = tmp->next){
        if (tmp->TOKEN == CHEVRON_LEFT_TOKEN)
            my_printf(" %s", "CHEVRON_LEFT_TOKEN");
        if (tmp->TOKEN == CHEVRON_RIGHT_TOKEN)
            my_printf(" %s", "CHEVRON_RIGHT_TOKEN");
        if (tmp->TOKEN == AMPERSAND_TOKEN)
            my_printf(" %s", "AMPERSAND_TOKEN");
        if (tmp->TOKEN == PIPE_TOKEN)
            my_printf(" %s", "PIPE_TOKEN");
        if (tmp->TOKEN == SEMICOLON_TOKEN)
            my_printf(" %s", "SEMICOLON_TOKEN");
        if (tmp->TOKEN == ERROR_TOKEN)
            my_printf(" %s", "ERROR_TOKEN");
        if (tmp->TOKEN == COMMAND_ARG_TOKEN)
            my_printf(" %s", "COMMAND_ARG_TOKEN");
        draw_cmd_advanced(tmp);
    }
    my_putchar('\n', 1);
}

int msg(int exit_code, int port, int nb, ...)
{
    va_list list;

    va_start(list, nb);
    for (int i = 0; i < nb; ++i)
        my_putstr(va_arg(list, char *), port);
    va_end(list);
    return exit_code;
}

int start_endless_core(storage_bag_t *storage)
{
    int exit_code = open_rc(storage);
    int exit_tmp;

    storage->allow_history = (storage->is_tty) ? false : true;
    storage->is_exit = 0;
    while (storage->is_exit == 0){
        exec_precmd(storage);
        if (storage->is_tty == false){
            enable_raw_mode();
            line_edition(storage);
            exit_tmp = run_prompt(storage);
        } else
            exit_tmp = run_prompt_tty(storage);
        if (storage->is_exit != 1)
            exit_code = exit_tmp;
    }
    save_history(&storage->history);
    if (storage->is_tty == false)
        my_putstr("exit\n", 1);
    return exit_code;
}

int main(int ac, char **av, char **env)
{
    int exit_code;
    storage_bag_t storage;

    if (ac > 2 || (ac == 2 && my_strcmp(av[1], "-c") != 0))
        return ERR;
    init_42sh(&storage, env);
    if (!isatty(STDIN_FILENO) || (ac == 2))
        storage.is_tty = true;
    get_userdata(&storage);
    load_history(&storage.history);
    exit_code = start_endless_core(&storage);
    clean_42sh(&storage);
    return exit_code;
}
