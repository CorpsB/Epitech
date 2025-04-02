/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** re_build_env.c
*/

#include "my.h"

static char *var_val(char **env, int i)
{
    char *result;

    result = my_substr(env[i], str_len_to(env[i], 0, '=') + 1,
    my_strlen(env[i]));
    return result;
}

static char *var_name(char **env, int i)
{
    char *result;

    result = my_substr(env[i], 0, str_len_to(env[i], 0, '='));
    return result;
}

void re_build_env(char **env, linked_t **l_env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_put_in_list(l_env, var_name(env, i), var_val(env, i));
    return;
}

void change_env(char ***mem_env, linked_t *list, char sep)
{
    char **env = malloc(sizeof(char *) * (my_list_size(list) + 1));
    linked_t *tmp = list;
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next){
        env[i] = my_strstr(tmp->name, tmp->value, '=');
        ++i;
    }
    env[i] = NULL;
    if (*mem_env != NULL)
        free_table(*mem_env);
    *mem_env = env;
}
