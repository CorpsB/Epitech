/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** history.c
*/

#include "../../include/shell.h"

static int is_double(char *result, char tmp)
{
    int size = my_strlen(result);

    if (size == 1 && result[size - 1] == tmp)
        return 1;
    if (size > 1 && result[size - 1] == tmp && result[size - 2] != tmp)
        return 1;
    return 0;
}

static void other_token(cmd_data_t *data, char **result)
{
    if (data->TOKEN == AMPERSAND_TOKEN)
        *result = (is_double(*result, '&') ? my_strcat(*result, "&") :
    my_strcat(*result, " &"));
    if (data->TOKEN == PIPE_TOKEN)
        *result = (is_double(*result, '|') ? my_strcat(*result, "|") :
    my_strcat(*result, " |"));
    if (data->TOKEN == CHEVRON_LEFT_TOKEN)
        *result = (is_double(*result, '<') ? my_strcat(*result, "<") :
    my_strcat(*result, " <"));
    if (data->TOKEN == CHEVRON_RIGHT_TOKEN)
        *result = (is_double(*result, '>') ? my_strcat(*result, ">") :
    my_strcat(*result, " >"));
    if (data->TOKEN == SEMICOLON_TOKEN)
        *result = my_strcat(*result, " ;");
    if (data->TOKEN == PARENTHESE_START_TOKEN)
        *result = my_strcat(*result, " (");
    if (data->TOKEN == PARENTHESE_END_TOKEN)
        *result = my_strcat(*result, " )");
}

char *get_history_by_id(history_t *list, int id)
{
    for (history_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (tmp->id == id)
            return tmp->cmd_line;
    return NULL;
}

char *get_actual_time(void)
{
    char *temps;
    time_t temp;

    time(&temp);
    temps = malloc(MAX_TIME_LENGTH * sizeof(char));
    strftime(temps, MAX_TIME_LENGTH, "%H:%M", localtime(&temp));
    return temps;
}

char *get_raw_cmd_from_build(int *i_max, cmd_data_t *data)
{
    char *result = my_strdup("");

    for (cmd_data_t *tmp = data; tmp != NULL; tmp = tmp->next)
        if (tmp->TOKEN == COMMAND_TOKEN || tmp->TOKEN == COMMAND_ARG_TOKEN)
            result = s_sepmerge(result, tmp->value, ' ');
        else
            other_token(tmp, &result);
    *i_max = my_strlen(result) - 1;
    if (*i_max > -1){
        for (int i = 1; i <= *i_max; i++)
            result[i - 1] = result[i];
        result[*i_max] = '\0';
    }
    return result;
}

void history(storage_bag_t *storage, cmd_data_t *data)
{
    int i_max;
    char *result = get_raw_cmd_from_build(&i_max, data);

    if (storage->is_tty)
        return;
    if (i_max == -1 || my_strcmp(result, storage->history->cmd_line) == 0 ||
    result[0] == '!'){
        free(result);
        return;
    }
    storage->prompt.max_id = l_add_history(&storage->history, result,
    get_actual_time());
}
