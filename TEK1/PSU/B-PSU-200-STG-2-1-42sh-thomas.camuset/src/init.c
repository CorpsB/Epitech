/*
** EPITECH PROJECT, 2024
** INIT
** File description:
** Yes.
*/

#include "../include/shell.h"

static void build_42sh_path(storage_bag_t *storage)
{
    int i = 0;

    getcwd(storage->path_to_42sh, 1000);
    for (; storage->path_to_42sh[i] != '\0'; ++i);
    s_copy(&storage->path_to_42sh[i], "/42sh");
    storage->path_to_42sh[i + 5] = '\0';
}

void init_42sh(storage_bag_t *storage, char **env)
{
    storage->prompt.actual_id = 0;
    storage->env = a_dup(env);
    storage->pathlist = get_pathlist(env);
    storage->exit_code = 0;
    storage->history = NULL;
    storage->prompt.cursor_offset = 0;
    storage->prompt.max_id = l_add_history(&storage->history,
    my_strdup(""), my_strdup(""));
    storage->allow_history = false;
    storage->alias = NULL;
    storage->set = NULL;
    storage->prompt.eof_count = 1;
    storage->prompt.clipboard = NULL;
    storage->is_tty = false;
    build_42sh_path(storage);
}

void clean_42sh(storage_bag_t *storage)
{
    a_free(storage->pathlist);
    a_free(storage->env);
    l_free_history(&storage->history);
    free(storage->username);
    l_free_var(&storage->alias);
    l_free_var(&storage->set);
    if (storage->prompt.clipboard != NULL)
        free(storage->prompt.clipboard);
}
