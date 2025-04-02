/*
** EPITECH PROJECT, 2023
** lib
** File description:
** array_to_list.c
*/

#include "../my.h"

static char *var_val(char **env, int i)
{
    int column_env = 0;
    char *result;
    int column_l = 0;

    for (; env[i][column_env] != '='; column_env++);
    column_env++;
    result = malloc(sizeof(char) * str_len_to(env[i], 0, '\0'));
    for (; env[i][column_env] != '\0'; column_env++) {
        result[column_l] = env[i][column_env];
        column_l++;
    }
    result[column_l] = '\0';
    return result;
}

static char *var_name(char **env, int i)
{
    char *result = malloc(sizeof(char) * (str_len_to(env[i], 0, '=') + 1));
    int column = 0;

    for (; env[i][column] != '='; column++) {
        result[column] = env[i][column];
    }
    result[column] = '\0';
    return result;
}

// /**
//  * Cette fonction transforme un char ** en liste chainée.
// */
// void re_build_env(char **env, linked_t **l_env)
// {
//     for (int i = 0; env[i] != NULL; i++) {
//         my_put_in_list(l_env, var_name(env, i), var_val(env, i));
//     }
//     return;
// }
