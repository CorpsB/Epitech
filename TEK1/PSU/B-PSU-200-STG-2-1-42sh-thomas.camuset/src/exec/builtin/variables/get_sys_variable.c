/*
** EPITECH PROJECT, 2024
** DIRECTORY HANDLER
** File description:
** Change working directory.
*/

#include "../../../../include/shell.h"

char *get_variable_set(var_list_t *list, char *key)
{
    for (var_list_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->name, key) == 0)
            return tmp->value;
    return NULL;
}

char *get_sys_variable(storage_bag_t *storage, char *key)
{
    char *res;

    res = get_variable_set(storage->set, key);
    if (res != NULL)
        return my_strdup(res);
    res = get_variable(storage->env, key);
    if (res != NULL)
        return res;
    return NULL;
}
