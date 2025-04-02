/*
** EPITECH PROJECT, 2024
** OPEN_RC
** File description:
** Open 42shrc file and store his content after parsing it.
*/

#include "../../../include/shell.h"

void exec_precmd(storage_bag_t *storage)
{
    var_list_t *alias_ptr = get_alias_ptr(storage->alias, "precmd");

    if (alias_ptr != NULL)
        run_command(storage, alias_ptr->value);
}

void exec_cwdcmd(storage_bag_t *storage)
{
    var_list_t *alias_ptr = get_alias_ptr(storage->alias, "cwdcmd");

    if (alias_ptr != NULL)
        run_command(storage, alias_ptr->value);
}
