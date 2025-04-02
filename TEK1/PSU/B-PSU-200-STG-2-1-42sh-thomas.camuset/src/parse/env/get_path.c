/*
** EPITECH PROJECT, 2024
** PATH HANDLER
** File description:
** Retrieve PATH variables.
*/

#include "../../../include/shell.h"

static int is_edit_line(char *arg)
{
    int i = 0;

    for (; arg[i] != '\0' && arg[i] != '='; ++i);
    if (arg[i] == '=')
        return i;
    return -1;
}

char *get_variable(char **env, char *arg)
{
    int cmp_result = -1;
    int equal_pos;

    for (int i = 0; env[i] != NULL; ++i){
        equal_pos = is_edit_line(env[i]);
        if (equal_pos != -1)
            cmp_result = my_strncmp(env[i], arg, equal_pos);
        if (cmp_result == 0)
            return my_substr(env[i], equal_pos + 1, my_strlen(env[i]));
    }
    return NULL;
}

int get_pathline(char **env, char *arg)
{
    int cmp_result = -1;
    int equal_pos;

    for (int i = 0; env[i] != NULL; ++i){
        equal_pos = is_edit_line(env[i]);
        if (equal_pos != -1)
            cmp_result = my_strncmp(env[i], arg, equal_pos);
        if (cmp_result == 0)
            return i;
    }
    return -1;
}

char **get_pathlist(char **env)
{
    char *pathline = get_variable(env, "PATH");
    char **pathlist;

    if (pathline == NULL)
        return NULL;
    if (pathline[0] == '\0'){
        free(pathline);
        return NULL;
    }
    pathlist = a_convert_s(pathline, ':', ':');
    if (pathlist == NULL){
        free(pathline);
        return NULL;
    }
    free(pathline);
    return pathlist;
}
