/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** cd.c
*/

#include "my.h"

static int change_old_pwd(linked_t **list)
{
    char *filepath = malloc(sizeof(char) * 1024);
    size_t size = sizeof(char) * 1024;
    linked_t *search = *list;
    linked_t *tmp = *list;
    int id = search_from_list(search, "OLDPWD");

    getcwd(filepath, size);
    if (id == -1)
        return my_put_in_list(list, "OLDPWD", filepath);
    for (; tmp->id != id && tmp != NULL; tmp = tmp->next);
    tmp->value = filepath;
    return 0;
}

static void change_pwd(linked_t *list)
{
    linked_t *search = list;
    linked_t *tmp = list;
    char *filepath = malloc(sizeof(char) * 1024);
    size_t size = sizeof(char) * 1024;
    int nbr = search_from_list(search, "PWD");

    getcwd(filepath, size);
    for (; tmp->id != nbr; tmp = tmp->next);
    free(tmp->value);
    tmp->value = filepath;
}

static int cd_last(linked_t **env)
{
    linked_t *tmp = *env;
    int id = 0;

    id = search_from_list(tmp, "OLDPWD");
    if (id == -1) {
        my_error(": No such file or directory.");
        return 1;
    }
    for (; tmp->id != id; tmp = tmp->next);
    chdir(tmp->value);
    change_pwd(*env);
}

bool is_a_dir(char *filepath)
{
    struct stat info;

    stat(filepath, &info);
    if (S_ISDIR(info.st_mode))
        return true;
    return false;
}

static int error_searcher(char **infos)
{
    if (table_len(infos) > 2) {
        my_error("cd: Too many arguments.\n");
        return 1;
    }
    if (my_strcmp(infos[1], "~") == 1 || my_strcmp(infos[1], "-"))
        return 0;
    if (access(infos[1], F_OK) == -1) {
        my_error(infos[1]);
        my_error(": No such file or directory.\n");
        return 1;
    }
    if (access(infos[1], R_OK) == -1) {
        my_error(infos[1]);
        my_error(": Permission denied.\n");
        return 1;
    }
    if (!is_a_dir(infos[1])) {
        my_error(infos[1]);
        my_error(": Not a directory.\n");
    }
}

int change_directory(linked_t **env, char **infos)
{
    linked_t *tmp = *env;

    if (table_len(infos) == 1 || (my_strcmp(infos[1], "~") == 1 &&
    table_len(infos) == 2)) {
        change_old_pwd(env);
        for (; my_strcmp("HOME", tmp->name) != 1; tmp = tmp->next);
        chdir(tmp->value);
        change_pwd(*env);
        return 0;
    }
    if (error_searcher(infos) == 1)
        return 1;
    if (my_strcmp(infos[1], "-") == 1) {
        return cd_last(env);
    }
    change_old_pwd(env);
    chdir(infos[1]);
    change_pwd(*env);
    return 0;
}
