/*
** EPITECH PROJECT, 2023
** KJ_FREE_LIST
** File description:
** Free all content of a linked list.
*/

#include "../../../include/project.h"
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

void l_free_shema(champion_shema_t **list)
{
    champion_shema_t *target;
    champion_shema_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}

void l_free_champion(champions_t **list)
{
    champions_t *target;
    champions_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}
