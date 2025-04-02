/*
** EPITECH PROJECT, 2024
** UNSETENV
** File description:
** Remove variables from PATH.
*/

#include "../../../../include/shell.h"

static int remove_env(storage_bag_t *storage, char *arg)
{
    char **new_env;
    int pathline;
    int j = 0;

    pathline = get_pathline(storage->env, arg);
    if (pathline == -1)
        return 0;
    new_env = malloc(sizeof(char *) * a_size(storage->env));
    for (int i = 0; storage->env[i] != NULL; ++i)
        if (i != pathline){
            new_env[j] = my_strdup(storage->env[i]);
            ++j;
        }
    new_env[j] = NULL;
    a_free(storage->env);
    storage->env = new_env;
    return 0;
}

int unset_env(storage_bag_t *storage, char **data)
{
    int exit_code = 0;

    if (a_size(data) == 1)
        return msg(ERR, 2, 1, "unsetenv: Too few arguments.\n");
    for (int i = 0; data[i] != NULL; ++i)
        remove_env(storage, data[i]);
    return exit_code;
}
