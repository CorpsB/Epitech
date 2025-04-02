/*
** EPITECH PROJECT, 2024
** PACKAGE CREATOR
** File description:
** Yes.
*/

#include "../../../include/shell.h"

int parse_or_operator(storage_bag_t *storage, cmd_data_t *line)
{
    cmd_data_t *cmd;
    cmd_data_t *next;
    int exit_code = 0;

    if (line->TOKEN == SEMICOLON_TOKEN && line->next == NULL){
        l_cmd_free(&line);
        return 0;
    }
    for (cmd_data_t *tmp = line; tmp != NULL; tmp = next){
        for (cmd = tmp; cmd->next != NULL && !(cmd->TOKEN == PIPE_TOKEN &&
        cmd->next->TOKEN == PIPE_TOKEN); cmd = cmd->next);
        next = cmd->next;
        cmd->next = NULL;
        exit_code = parse_and_operator(storage, tmp);
        if (exit_code == 0){
            l_cmd_free(&next);
            break;
        }
    }
    return exit_code;
}
