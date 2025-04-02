/*
** EPITECH PROJECT, 2023
** MY_REV_LIST
** File description:
** Reverse a linked list using pointers.
*/

#include "../../../include/shell.h"
void l_reverse(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}

void l_reverse_history(history_t **list)
{
    history_t *tmp = *list;
    history_t *prev = NULL;
    history_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}

void l_reverse_var(var_list_t **list)
{
    var_list_t *tmp = *list;
    var_list_t *prev = NULL;
    var_list_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}

void l_cmd_reverse(cmd_data_t **list)
{
    cmd_data_t *tmp = *list;
    cmd_data_t *prev = NULL;
    cmd_data_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}

void l_pipe_reverse(pipe_data_t **list)
{
    pipe_data_t *tmp = *list;
    pipe_data_t *prev = NULL;
    pipe_data_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}
