/*
** EPITECH PROJECT, 2024
** PACKAGE CREATOR
** File description:
** Yes.
*/

#include "../../../include/shell.h"

int parse_semicolon(storage_bag_t *storage, cmd_data_t *line)
{
    cmd_data_t *cmd;
    cmd_data_t *next;
    int exit_code = 0;

    if (is_parsing_error(line)){
        l_cmd_free(&line);
        return ERR;
    }
    for (cmd_data_t *tmp = line; tmp != NULL; tmp = next){
        for (cmd = tmp; cmd->next != NULL &&
        cmd->next->TOKEN != SEMICOLON_TOKEN; cmd = cmd->next);
        next = cmd->next;
        cmd->next = NULL;
        exit_code = parse_or_operator(storage, tmp);
    }
    return exit_code;
}
