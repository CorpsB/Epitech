/*
** EPITECH PROJECT, 2024
** ALIAS HANDLER
** File description:
** Make aliases
*/

#include "../../../../../include/shell.h"

static int is_syntax_error(char *name)
{
    if (!((name[0] >= 'A' && name[0] <= 'Z') ||
    (name[0] >= 'a' && name[0] <= 'z') || name[0] == '_'))
        return 1;
    if (!is_alpha_name(name))
        return 1;
    return 0;
}

var_list_t *get_alias_ptr(var_list_t *list, char *search)
{
    for (var_list_t *tmp = list; tmp != NULL; tmp = tmp->next)
        if (my_strcmp(tmp->name, search) == 0)
            return tmp;
    return NULL;
}

static void edit_alias_content(storage_bag_t *storage, char **cmd,
    var_list_t *alias_ptr, int size)
{
    char *args;

    if (size > 2)
        args = s_convert_a(cmd, 2);
    if (alias_ptr == NULL){
        if (size == 2)
            return;
        l_add_var(&storage->alias, my_strdup(cmd[1]), args);
    } else {
        if (size == 2){
            my_printf("%s\n", get_alias_ptr(storage->alias, cmd[1])->value);
            return;
        }
        free(alias_ptr->value);
        alias_ptr->value = args;
    }
}

int alias(storage_bag_t *storage, char **cmd)
{
    var_list_t *alias_ptr;
    int size = a_size(cmd);

    if (size == 1){
        l_display_var(storage->alias);
        return 0;
    }
    if (is_syntax_error(cmd[1]))
        return 0;
    alias_ptr = get_alias_ptr(storage->alias, cmd[1]);
    edit_alias_content(storage, cmd, alias_ptr, size);
    return 0;
}
