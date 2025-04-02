/*
** EPITECH PROJECT, 2023
** KJ_FREE_LIST
** File description:
** Free all content of a linked list.
*/

#include "../../../include/shell.h"
void l_free(linked_list_t **list)
{
    linked_list_t *target;
    linked_list_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->data);
        tmp = tmp->next;
        free(target);
    }
}

void l_free_history(history_t **list)
{
    history_t *target;
    history_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->cmd_line);
        free(tmp->temps);
        tmp = tmp->next;
        free(target);
    }
}

void l_cmd_free(cmd_data_t **list)
{
    cmd_data_t *target;
    cmd_data_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        if (tmp->value != NULL)
            free(tmp->value);
        tmp = tmp->next;
        free(target);
    }
}

void l_pipe_free(pipe_data_t **list)
{
    pipe_data_t *target;
    pipe_data_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        a_free(tmp->build_cmd);
        l_cmd_free(&tmp->raw_cmd);
        tmp = tmp->next;
        free(target);
    }
}

void l_free_var(var_list_t **list)
{
    var_list_t *target;
    var_list_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        if (tmp->name != NULL)
            free(tmp->name);
        if (tmp->value != NULL)
            free(tmp->value);
        tmp = tmp->next;
        free(target);
    }
}
