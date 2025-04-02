/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** set.c
*/

#include "../../../../../include/shell.h"

static char **pre_set(char **cmd)
{
    char *s_cmd = s_convert_a(cmd, 0);
    char **result = get_tab_by_arg(s_cmd, "=");

    free(s_cmd);
    return result;
}

static void delete(storage_bag_t *storage, char *cmd)
{
    var_list_t *tmp = storage->set;

    for (; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(cmd, tmp->name) == 0){
            l_remove_var(&storage->set, tmp);
            return;
        }
}

static bool error(char *cmd)
{
    bool error = true;
    bool alpha_error = is_alpha_name(cmd);

    if (cmd[0] >= 'a' && cmd[0] <= 'z')
        error = false;
    if (cmd[0] >= 'A' && cmd[0] <= 'Z')
        error = false;
    if (error)
        my_putstr("set: Variable name must begin with a letter.\n", 2);
    if (!error && !alpha_error) {
        my_putstr("set: Variable name must contain alphanumeric ", 2);
        my_putstr("characters.\n", 2);
        return true;
    }
    return error;
}

int set(storage_bag_t *storage, char **cmd)
{
    char **pmd = pre_set(cmd);

    for (int i = 1; pmd[i] != NULL; ++i){
        delete(storage, pmd[i]);
        if (error(pmd[i]))
            return 1;
        if (pmd[i + 1] != NULL && pmd[i + 1][0] == '=' && pmd[i + 2]){
            l_add_var(&storage->set, my_strdup(pmd[i]), my_strdup(pmd[i + 2]));
            i += 2;
            continue;
        }
        if (pmd[i + 1] && pmd[i + 1][0] == '=' && pmd[i + 2] == NULL){
            l_add_var(&storage->set, my_strdup(pmd[i]), NULL);
            i += 1;
            continue;
        }
        l_add_var(&storage->set, my_strdup(pmd[i]), NULL);
    }
    a_free(pmd);
    return 0;
}

int unset(storage_bag_t *storage, char **cmd)
{
    if (a_size(cmd) == 1) {
        my_putstr("unset: Too few arguments.\n", 2);
        return 1;
    }
    for (int i = 1; cmd[i] != NULL; i++)
        delete(storage, cmd[i]);
    return 0;
}
