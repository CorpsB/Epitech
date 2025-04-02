/*
** EPITECH PROJECT, 2024
** CREATE ROOM LIST
** File description:
** Build a list of rooms.
*/

#include "../../../include/amazed.h"

void free_room_list(room_list_t **list)
{
    room_list_t *target;
    room_list_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        free(tmp->name);
        free_room_links(&tmp->list);
        tmp = tmp->next;
        free(target);
    }
}
