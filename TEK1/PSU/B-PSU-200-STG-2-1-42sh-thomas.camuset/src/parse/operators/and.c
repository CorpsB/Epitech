/*
** EPITECH PROJECT, 2024
** PACKAGE CREATOR
** File description:
** Yes.
*/

#include "../../../include/shell.h"

static int free_start_ampersands(cmd_data_t *line, cmd_data_t *prev,
    int exit_code)
{
    if (prev != NULL){
        prev->next = NULL;
        l_cmd_free(&line);
    }
    return exit_code;
}

int parse_and_operator(storage_bag_t *storage, cmd_data_t *line)
{
    cmd_data_t *cmd;
    cmd_data_t *next;
    cmd_data_t *prev = NULL;
    cmd_data_t *tmp = line;
    int exit_code = 0;

    for (; tmp != NULL && tmp->TOKEN == AMPERSAND_TOKEN; tmp = tmp->next)
        prev = tmp;
    for (; tmp != NULL; tmp = next){
        for (cmd = tmp; cmd->next != NULL && !(cmd->TOKEN == AMPERSAND_TOKEN &&
        cmd->next->TOKEN == AMPERSAND_TOKEN); cmd = cmd->next);
        next = cmd->next;
        cmd->next = NULL;
        exit_code = parse_pipe(storage, tmp);
        if (exit_code != 0){
            l_cmd_free(&next);
            break;
        }
    }
    return free_start_ampersands(line, prev, exit_code);
}
