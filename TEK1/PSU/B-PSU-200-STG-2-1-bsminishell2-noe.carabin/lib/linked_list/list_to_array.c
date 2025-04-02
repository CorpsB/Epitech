/*
** EPITECH PROJECT, 2023
** lib
** File description:
** list_to_array.c
*/

#include "../my.h"

// static int my_s(char *something)
// {
//     return my_strlen(something);
// }

// /**
//  * Cette fonction transforme une liste chainée en char **.
// */
// void change_env(char ***mem_env, linked_t *list, char sep)
// {
//     char **env;
//     linked_t *tp = list;
//     int l = 0;
//     int column = 0;

//     env = malloc(sizeof(char *) * (my_list_size(list) + 1));
//     for (; tp != NULL; tp = tp->next) {
//         env[l] = malloc(sizeof(char) * (my_s(tp->name) +
// my_s(tp->value) + 2));
//         for (; tp->name[column] != '\0'; column++)
//             env[l][column] = tp->name[column];
//         env[l][column] = sep;
//         column++;
//         for (int i = column; tp->value[column - i] != '\0'; column++)
//             env[l][column] = tp->value[column - i];
//         env[l][column] = '\0';
//         column = 0;
//         l++;
//     }
//     env[l] = NULL;
//     if (!mem_env)
//     free_table(*mem_env);
//     *mem_env = env;
// }
