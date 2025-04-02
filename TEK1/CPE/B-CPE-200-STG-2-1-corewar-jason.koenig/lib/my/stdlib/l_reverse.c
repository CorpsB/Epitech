/*
** EPITECH PROJECT, 2023
** MY_REV_LIST
** File description:
** Reverse a linked list using pointers.
*/

#include "../../../include/project.h"
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

void l_reverse_shema(champion_shema_t **list)
{
    champion_shema_t *tmp = *list;
    champion_shema_t *prev = NULL;
    champion_shema_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}

void l_reverse_champion(champions_t **list)
{
    champions_t *tmp = *list;
    champions_t *prev = NULL;
    champions_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}
