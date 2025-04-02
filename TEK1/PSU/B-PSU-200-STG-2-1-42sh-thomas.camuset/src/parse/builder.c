/*
** EPITECH PROJECT, 2024
** PACKAGE CREATOR
** File description:
** Yes.
*/

#include "../../include/shell.h"

int get_chevron_data(cmd_data_t **tmp, char **stock, int type)
{
    int mode = 0;

    if ((*tmp)->next->TOKEN == type){
        if (type == CHEVRON_LEFT_TOKEN)
            mode = 10;
        if (type == CHEVRON_RIGHT_TOKEN)
            mode = 1;
        (*tmp) = (*tmp)->next;
    }
    (*tmp) = (*tmp)->next;
    *stock = (*tmp)->value;
    (*tmp) = (*tmp)->next;
    return mode;
}

static void build_cmd_data(pipe_data_t **data, int mode,
    cmd_data_t *line, char *build_cmd)
{
    (*data)->build_cmd = a_convert_s(build_cmd, ' ', ' ');
    (*data)->mode = mode;
    (*data)->raw_cmd = line;
    (*data)->instance = false;
    free(build_cmd);
}

void command_builder(pipe_data_t **data, cmd_data_t *line)
{
    char *build_cmd = my_strdup("");
    char *left_cmd = NULL;
    char *right_cmd = NULL;
    int mode = 0;

    for (cmd_data_t *tmp = line; tmp != NULL;){
        if (tmp->TOKEN == CHEVRON_LEFT_TOKEN)
            mode += get_chevron_data(&tmp, &left_cmd, CHEVRON_LEFT_TOKEN);
        if (tmp != NULL && tmp->TOKEN == CHEVRON_RIGHT_TOKEN)
            mode += get_chevron_data(&tmp, &right_cmd, CHEVRON_RIGHT_TOKEN);
        if (tmp != NULL && (tmp->TOKEN == COMMAND_TOKEN ||
        tmp->TOKEN == COMMAND_ARG_TOKEN))
            build_cmd = s_sependmerge(build_cmd, tmp->value, ' ');
        if (tmp != NULL)
            tmp = tmp->next;
    }
    if (build_cmd[0] != '\0')
        build_cmd[my_strlen(build_cmd) - 1] = '\0';
    l_pipe_add(data, left_cmd, right_cmd);
    build_cmd_data(data, mode, line, build_cmd);
}
