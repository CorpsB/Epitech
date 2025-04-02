/*
** EPITECH PROJECT, 2023
** KJ_PUT_IN_CHAIN
** File description:
** Put a string into a linked list.
*/

#include "../../../include/shell.h"

void l_add(linked_list_t **list, void *arg)
{
    linked_list_t *s_list = malloc(sizeof(struct linked_list));

    s_list->data = arg;
    s_list->next = *list;
    *list = s_list;
}

void l_cmd_add(cmd_data_t **list, void *arg, int token)
{
    cmd_data_t *s_list = malloc(sizeof(struct cmd_data));

    s_list->value = arg;
    s_list->TOKEN = token;
    s_list->next = *list;
    *list = s_list;
}

void l_pipe_add(pipe_data_t **list, char *left, char *right)
{
    pipe_data_t *s_list = malloc(sizeof(struct pipe_data));

    s_list->chev_left = left;
    s_list->chev_right = right;
    s_list->next = *list;
    *list = s_list;
}

int l_add_history(history_t **list, char *line, char *temps)
{
    history_t *s_list = malloc(sizeof(struct history));

    s_list->temps = temps;
    s_list->cmd_line = line;
    s_list->next = *list;
    s_list->id = (*list != NULL ? (*list)->id + 1 : 0);
    *list = s_list;
    return s_list->id;
}

void l_add_var(var_list_t **list, char *name, char *value)
{
    var_list_t *s_list = malloc(sizeof(struct var_list));

    s_list->name = name;
    s_list->value = value;
    s_list->next = *list;
    *list = s_list;
}
