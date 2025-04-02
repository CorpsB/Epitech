/*
** EPITECH PROJECT, 2024
** INHIBITORS
** File description:
** Things that ignore parsing.
*/

#include "../../../include/shell.h"

int change_history_to_value(storage_bag_t *storage, cmd_data_t *tmp)
{
    char *hist;

    if (tmp->value[0] != '!')
        return 0;
    if (excl_history(storage, &tmp->value, false) == ERR)
        return msg(ERR, 2, 2, &tmp->value[1], ": Event not found.\n");
    hist = my_strdup(find_hist(storage, &tmp->value[1]));
    free(tmp->value);
    tmp->value = hist;
    return 0;
}

int redirect_history(storage_bag_t *storage, cmd_data_t *data)
{
    int err_code = 0;

    for (cmd_data_t *tmp = data; tmp != NULL; tmp = tmp->next){
        if (tmp->TOKEN == COMMAND_TOKEN || tmp->TOKEN == COMMAND_ARG_TOKEN)
            err_code = change_history_to_value(storage, tmp);
        if (err_code == ERR)
            return ERR;
    }
    return 0;
}
