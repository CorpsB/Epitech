/*
** EPITECH PROJECT, 2024
** INHIBITORS
** File description:
** Things that ignore parsing.
*/

#include "../../../include/shell.h"

void rebuild_val(cmd_data_t *tmp, char *result, int start, int end)
{
    char *start_str = my_substr(tmp->value, 0, start);
    char *end_str = my_substr(tmp->value, end + 1, my_strlen(tmp->value));

    free(tmp->value);
    tmp->value = start_str;
    tmp->value = my_strcat(tmp->value, result);
    tmp->value = my_strcat(tmp->value, end_str);
    free(end_str);
    free(result);
}

void edit_backticks(storage_bag_t *storage, cmd_data_t *tmp)
{
    int start = s_search(tmp->value, '`', '`');
    char *str;
    char *result;
    char *tab[] = {"./42sh", "-c", NULL};
    int end;

    if (start == -1)
        return;
    for (end = start + 1; tmp->value[end] != '\0' &&
    tmp->value[end] != '`'; ++end);
    if (tmp->value[end] == '\0')
        return;
    str = my_substr(tmp->value, start + 1, end);
    result = exec_42sh(storage, str, tab);
    free(str);
    return rebuild_val(tmp, result, start, end);
}

void replace_backticks(storage_bag_t *storage, cmd_data_t **line)
{
    for (cmd_data_t *tmp = *line; tmp != NULL; tmp = tmp->next)
        if (tmp->TOKEN == COMMAND_TOKEN || tmp->TOKEN == COMMAND_ARG_TOKEN)
            edit_backticks(storage, tmp);
}
