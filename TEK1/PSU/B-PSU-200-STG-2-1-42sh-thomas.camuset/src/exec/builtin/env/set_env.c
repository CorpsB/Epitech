/*
** EPITECH PROJECT, 2024
** SETENV
** File description:
** Add data to env or edit it.
*/

#include "../../../../include/shell.h"

int is_alpha_name(char *str)
{
    for (int i = 1; str[i] != '\0'; ++i)
        if (!(str[i] >= '0' && str[i] <= '9') &&
        !(str[i] >= 'A' && str[i] <= 'Z') &&
        !(str[i] >= 'a' && str[i] <= 'z') && str[i] != '_')
            return 0;
    return 1;
}

static int is_alpha_letter(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') || c == '_')
        return 1;
    return 0;
}

int add_env(storage_bag_t *storage, char *arg, char *value)
{
    char **new_env;
    int i = 0;

    new_env = malloc(sizeof(char *) * (a_size(storage->env) + 2));
    for (; storage->env[i] != NULL; ++i)
        new_env[i] = my_strdup(storage->env[i]);
    new_env[i] = my_strdup(arg);
    if (value != NULL)
        new_env[i] = s_sepmerge(new_env[i], value, '=');
    else
        new_env[i] = my_strcat(new_env[i], "=");
    new_env[i + 1] = NULL;
    a_free(storage->env);
    storage->env = new_env;
    return 0;
}

int edit_env(storage_bag_t *storage, char *arg, char *value, int pathline)
{
    free(storage->env[pathline]);
    storage->env[pathline] = my_strdup(arg);
    if (value != NULL)
        storage->env[pathline] = s_sepmerge(storage->env[pathline],
        value, '=');
    else
        storage->env[pathline] = my_strcat(storage->env[pathline], "=");
    if (my_strcmp(arg, "PATH") == 0){
        a_free(storage->pathlist);
        storage->pathlist = get_pathlist(storage->env);
    }
    return 0;
}

int choice_set_method(storage_bag_t *storage, char *arg, char *value)
{
    int pathline;

    if (!is_alpha_letter(arg[0]))
        return msg(ERR, 2, 2, "setenv: Variable name must ",
        "begin with a letter.\n");
    if (!is_alpha_name(arg))
        return msg(ERR, 2, 2, "setenv: Variable name must ",
        "contain alphanumeric characters.\n");
    if (value != NULL)
        if (value[0] == '=')
            return msg(ERR, 2, 1, "setenv: Directory stack not that deep.\n");
    pathline = get_pathline(storage->env, arg);
    if (pathline == -1)
        return add_env(storage, arg, value);
    return edit_env(storage, arg, value, pathline);
}

int set_env(storage_bag_t *storage, char **data)
{
    int size = a_size(data);

    if (size == 1)
        return display_env(storage, data);
    if (size > 3)
        return msg(ERR, 2, 1, "setenv: Too many arguments.\n");
    if (size == 2)
        return choice_set_method(storage, data[1], NULL);
    return choice_set_method(storage, data[1], data[2]);
}
