/*
** EPITECH PROJECT, 2024
** ALIAS HANDLER
** File description:
** Make aliases
*/

#include "../../../../../include/shell.h"

char *get_alias_redirect(storage_bag_t *storage, char *cmd)
{
    var_list_t *start = get_alias_ptr(storage->alias, cmd);
    var_list_t redirect;

    if (start == NULL || my_strcmp(start->name, start->value) == 0)
        return NULL;
    redirect.name = cmd;
    while (start != NULL){
        redirect.value = start->value;
        if (my_strcmp(redirect.name, redirect.value) == 0)
            return NULL;
        start = get_alias_ptr(storage->alias, redirect.value);
    }
    return redirect.value;
}

int redirect_aliases(storage_bag_t *storage, cmd_data_t **data)
{
    char *redirect = NULL;
    char **replace_data;
    cmd_data_t *next;

    for (cmd_data_t *tmp = *data; tmp != NULL; tmp = next){
        next = tmp->next;
        if (tmp->TOKEN == COMMAND_TOKEN)
            redirect = get_alias_redirect(storage, tmp->value);
        if (tmp->TOKEN == COMMAND_TOKEN && redirect != NULL){
            replace_data = a_convert_s(redirect, ' ', '\t');
            l_replace_cmd(data, tmp, replace_data);
            a_free(replace_data);
        }
    }
}

int redirect_alias_test_loop(storage_bag_t *storage, char *cmd)
{
    var_list_t *start = get_alias_ptr(storage->alias, cmd);
    var_list_t redirect;

    if (start == NULL || my_strcmp(start->name, start->value) == 0)
        return -1;
    redirect.name = cmd;
    while (start != NULL){
        redirect.value = start->value;
        if (my_strcmp(redirect.name, redirect.value) == 0)
            return msg(ERR, 2, 1, "Alias loop.\n");
        start = get_alias_ptr(storage->alias, redirect.value);
    }
    return -1;
}
