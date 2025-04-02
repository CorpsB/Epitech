/*
** EPITECH PROJECT, 2024
** 42sh PROJECT
** File description:
** Version: RELEASE 3.0
*/

#include "../../include/shell.h"

static int is_missing_name(cmd_data_t *tmp, cmd_data_t *prev,
    int type, int other)
{
    if (tmp->TOKEN == type){
        if (tmp->next == NULL ||
        (tmp->next->TOKEN == type && tmp->next->next == NULL) ||
        (tmp->next->TOKEN == type && tmp->next->next->TOKEN == type) ||
        tmp->next->TOKEN == other || tmp->next->TOKEN == PIPE_TOKEN ||
        tmp->next->TOKEN == AMPERSAND_TOKEN ||
        tmp->next->TOKEN == SEMICOLON_TOKEN)
            return 1;
    }
    return 0;
}

static int is_no_cmd(cmd_data_t *tmp, cmd_data_t *prev)
{
    if (prev != NULL)
        return 0;
    if (tmp->next == NULL)
        return 1;
    if (tmp->next->TOKEN == tmp->TOKEN)
        return 0;
    if (tmp->next->TOKEN == COMMAND_TOKEN ||
    tmp->next->TOKEN == COMMAND_ARG_TOKEN ||
    tmp->next->TOKEN == EXTERNAL_PARENTHESE_TOKEN)
        if (tmp->next->next != NULL &&
        (tmp->next->next->TOKEN == COMMAND_TOKEN ||
        tmp->next->next->TOKEN == COMMAND_ARG_TOKEN ||
        tmp->next->next->TOKEN == EXTERNAL_PARENTHESE_TOKEN))
            return 0;
    return 1;
}

static int is_invalid_cmd(cmd_data_t *tmp, cmd_data_t *prev)
{
    if (tmp->TOKEN == CHEVRON_LEFT_TOKEN ||
    tmp->TOKEN == CHEVRON_RIGHT_TOKEN)
        if ((prev != NULL && prev->TOKEN != COMMAND_TOKEN &&
        prev->TOKEN != EXTERNAL_PARENTHESE_TOKEN &&
        prev->TOKEN != COMMAND_ARG_TOKEN &&
        prev->TOKEN != CHEVRON_LEFT_TOKEN &&
        prev->TOKEN != CHEVRON_RIGHT_TOKEN) || is_no_cmd(tmp, prev))
            return 1;
    if (tmp->TOKEN == PIPE_TOKEN)
        if (tmp->next == NULL || prev == NULL)
            return 1;
    if (tmp->TOKEN == PIPE_TOKEN)
        if (tmp->next != NULL && tmp->next->TOKEN == PIPE_TOKEN &&
        tmp->next->next != NULL && tmp->next->next->TOKEN == PIPE_TOKEN)
            return 1;
    if (tmp->TOKEN == AMPERSAND_TOKEN)
        if (tmp->next != NULL && tmp->next->TOKEN == AMPERSAND_TOKEN &&
        tmp->next->next != NULL && tmp->next->next->TOKEN == AMPERSAND_TOKEN)
            return 1;
    return 0;
}

static int ambigous_in_red(cmd_data_t *tmp, cmd_data_t *prev, int *count)
{
    if (tmp->TOKEN == SEMICOLON_TOKEN){
        *count = 0;
        return 0;
    }
    if (tmp->TOKEN == CHEVRON_LEFT_TOKEN &&
    tmp->next->TOKEN != CHEVRON_LEFT_TOKEN)
        *count += 1;
    if (*count == 2)
        return 1;
    return 0;
}

static int ambigous_out_red(cmd_data_t *tmp, cmd_data_t *prev, int *count)
{
    if (tmp->TOKEN == SEMICOLON_TOKEN){
        *count = 0;
        return 0;
    }
    if (tmp->TOKEN == CHEVRON_RIGHT_TOKEN &&
    tmp->next->TOKEN != CHEVRON_RIGHT_TOKEN)
        *count += 1;
    if (*count == 2)
        return 1;
    return 0;
}

static int is_parsing_error_inside(cmd_data_t *tmp,
    cmd_data_t *prev, int count[2])
{
    if ((tmp->TOKEN == ERROR_TOKEN && tmp->next != NULL &&
    (tmp->next->TOKEN == CHEVRON_LEFT_TOKEN ||
    tmp->next->TOKEN == CHEVRON_RIGHT_TOKEN)) ||
    is_missing_name(tmp, prev, CHEVRON_LEFT_TOKEN, CHEVRON_RIGHT_TOKEN) ||
    is_missing_name(tmp, prev, CHEVRON_RIGHT_TOKEN, CHEVRON_LEFT_TOKEN))
        return msg(ERR, 2, 1, "Missing name for redirect.\n");
    if ((tmp->TOKEN == ERROR_TOKEN && tmp->next != NULL &&
    (tmp->next->TOKEN == AMPERSAND_TOKEN ||
    tmp->next->TOKEN == PIPE_TOKEN)) || is_invalid_cmd(tmp, prev))
        return msg(ERR, 2, 1, "Invalid null command.\n");
    if (ambigous_in_red(tmp, prev, &count[0]))
        return msg(ERR, 2, 1, "Ambigous input redirect.\n");
    if (ambigous_out_red(tmp, prev, &count[1]))
        return msg(ERR, 2, 1, "Ambigous output redirect.\n");
    return 0;
}

int is_parsing_error(cmd_data_t *line)
{
    cmd_data_t *prev = NULL;
    int count[2] = {0, 0};

    for (cmd_data_t *tmp = line; tmp != NULL; tmp = tmp->next){
        if (is_parsing_error_inside(tmp, prev, count))
            return 1;
        prev = tmp;
    }
    return 0;
}
