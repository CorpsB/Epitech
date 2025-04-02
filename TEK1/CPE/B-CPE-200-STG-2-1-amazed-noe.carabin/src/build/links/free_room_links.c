/*
** EPITECH PROJECT, 2024
** CREATE ROOM LIST
** File description:
** Build a list of rooms.
*/

#include "../../../include/amazed.h"

void free_room_links(room_link_t **list)
{
    room_link_t *target;
    room_link_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}
