/*
** EPITECH PROJECT, 2024
** ENV HANDLER
** File description:
** Access env and edit values.
*/

#include "../../../../include/shell.h"

int display_env(storage_bag_t *storage, char **cmd)
{
    int size = a_size(cmd);

    if (size != 1)
        return msg(ERR, 2, 3, "env: '", cmd[1],
        "': No such file or directory\n");
    a_display_s(storage->env);
    return 0;
}
