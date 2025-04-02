/*
** EPITECH PROJECT, 2024
** PACKAGE CREATOR
** File description:
** Yes.
*/

#include "../../../include/shell.h"

static bool is_parenthese(cmd_data_t *tmp)
{
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->TOKEN == EXTERNAL_PARENTHESE_TOKEN)
            return true;
    return false;
}

static void pre_builder_parenthese(pipe_data_t **data,
    cmd_data_t *tmp)
{
    l_pipe_add(data, NULL, NULL);
    (*data)->raw_cmd = tmp;
    parenthese_builder(*data, tmp);
    for (; tmp != NULL && tmp->TOKEN != EXTERNAL_PARENTHESE_TOKEN;
    tmp = tmp->next);
    (*data)->build_cmd = malloc(sizeof(char *) * 2);
    (*data)->build_cmd[0] = my_strdup(tmp->value);
    (*data)->build_cmd[1] = NULL;
}

int parse_pipe(storage_bag_t *storage, cmd_data_t *line)
{
    pipe_data_t *data = NULL;
    cmd_data_t *cmd;
    cmd_data_t *next;

    for (cmd_data_t *tmp = line; tmp != NULL; tmp = next){
        for (cmd = tmp; cmd->next != NULL && !(cmd->TOKEN == PIPE_TOKEN &&
        cmd->next->TOKEN != PIPE_TOKEN); cmd = cmd->next);
        next = cmd->next;
        cmd->next = NULL;
        if (is_parenthese(tmp))
            pre_builder_parenthese(&data, tmp);
        else
            command_builder(&data, tmp);
    }
    return run_pipe_command(storage, data);
}
