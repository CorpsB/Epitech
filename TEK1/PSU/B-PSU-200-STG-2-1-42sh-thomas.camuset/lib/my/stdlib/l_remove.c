/*
** EPITECH PROJECT, 2023
** DELETE_IN_LIST
** File description:
** Delete a node from a linked_list.
*/

#include "../../../include/base/my.h"
#include "../../../include/shell.h"

static void delete_arg(linked_list_t **begin, linked_list_t *tmp,
    linked_list_t *prev)
{
    if (prev == NULL)
        *begin = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp->data);
    free(tmp);
}

void l_remove(linked_list_t **list, linked_list_t *to_delete)
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (tmp != NULL){
        if (tmp == to_delete){
            next = tmp->next;
            delete_arg(list, tmp, prev);
            tmp = next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

static void delete_arg_var(var_list_t **begin, var_list_t *tmp,
    var_list_t *prev)
{
    if (prev == NULL)
        *begin = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp->name);
    free(tmp->value);
    free(tmp);
}

void l_remove_var(var_list_t **list, var_list_t *to_delete)
{
    var_list_t *tmp = *list;
    var_list_t *prev = NULL;
    var_list_t *next;

    while (tmp != NULL){
        if (tmp == to_delete){
            next = tmp->next;
            delete_arg_var(list, tmp, prev);
            tmp = next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

static void delete_arg_cmd(cmd_data_t **begin, cmd_data_t *tmp,
    cmd_data_t *prev)
{
    if (prev == NULL)
        *begin = tmp->next;
    else
        prev->next = tmp->next;
    if (tmp->value != NULL)
        free(tmp->value);
    free(tmp);
}

void l_remove_cmd(cmd_data_t **list, cmd_data_t *to_delete)
{
    cmd_data_t *tmp = *list;
    cmd_data_t *prev = NULL;
    cmd_data_t *next;

    while (tmp != NULL){
        if (tmp == to_delete){
            next = tmp->next;
            delete_arg_cmd(list, tmp, prev);
            tmp = next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void l_replace_cmd(cmd_data_t **list, cmd_data_t *tmp,
    char **replace_data)
{
    cmd_data_t *build;
    cmd_data_t *prev;
    cmd_data_t *next = tmp->next;
    int size = a_size(replace_data);

    free(tmp->value);
    tmp->value = my_strdup(replace_data[0]);
    prev = tmp;
    for (int i = 1; i < size; ++i){
        build = malloc(sizeof(struct cmd_data));
        build->value = my_strdup(replace_data[i]);
        build->TOKEN = COMMAND_ARG_TOKEN;
        build->next = NULL;
        prev->next = build;
        prev = build;
    }
    if (size > 1)
        build->next = next;
}
