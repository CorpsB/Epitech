/*
** EPITECH PROJECT, 2024
** ALIAS HANDLER
** File description:
** Make aliases
*/

#include "../../../../../include/shell.h"

int unalias(storage_bag_t *storage, char **cmd)
{
    if (a_size(cmd) == 1)
        return msg(ERR, 2, 1, "unalias: Too few arguments.\n");
    for (int i = 1; cmd[i] != NULL; ++i)
        l_remove_var(&storage->alias, get_alias_ptr(storage->alias, cmd[i]));
    return 0;
}
