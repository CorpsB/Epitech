/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin
** File description:
** setenv.c
*/

#include "my.h"

int search_from_list(linked_t *list, char *name)
{
    linked_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) != 0) {
            return tmp->id;
        }
    }
    return (-1);
}

static int my_board_size(char **something)
{
    int i = 0;

    if (something == NULL)
        return -1;
    for (; something[i] != NULL; i++);
    return i;
}

bool is_alpah_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < 'a' || str[i] > 'z') && str[i] != '_')
            return false;
    }
    return true;
}

int search_error(char **infos, int arg_nbr, linked_t **list)
{
    if (arg_nbr == 1) {
        show_env(*list, NULL);
        return 0;
    }
    if (arg_nbr > 3) {
        my_error("setenv: Too many arguments.\n");
        return 1;
    }
    if (infos[1][0] != '_' && (infos[1][0] < 'A' || infos[1][0] > 'Z') &&
    (infos[1][0] < 'a' || infos[1][0] > 'z')) {
        my_error("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (is_alpah_num(infos[1]))
        return -1;
    my_error("setenv: Variable name must contain alphanumeric character");
    my_error("s.\n");
    return 1;
}

static char *get_value(int nbr, char **infos)
{
    char *value = NULL;

    if (nbr == 3)
        value = infos[2];
    if (nbr == 2) {
        value = malloc(sizeof(char) * my_strlen("NO_VALUE\0"));
        value = "NO_VALUE\0";
    }
    return value;
}

int set_environement(char **infos, linked_t **list)
{
    linked_t *tmp = *list;
    char *value = NULL;
    int i = 0;
    int arg_nbr = my_board_size(infos);
    int error = -1;

    if (table_len(infos) == 1)
        return show_env(*list, infos);
    error = search_error(infos, arg_nbr, list);
    if (error == 1 || error == 0)
        return error;
    i = search_from_list(*list, infos[1]);
    value = get_value(arg_nbr, infos);
    if (i == -1)
        return my_put_in_list(list, my_strdup(infos[1]), my_strdup(value));
    for (; tmp->id != i; tmp = tmp->next);
    tmp->value = my_strdup(infos[2]);
    return 0;
}
