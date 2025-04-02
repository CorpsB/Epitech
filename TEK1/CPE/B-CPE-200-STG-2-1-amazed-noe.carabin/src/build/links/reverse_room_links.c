/*
** EPITECH PROJECT, 2024
** CREATE ROOM LIST
** File description:
** Build a list of rooms.
*/

#include "../../../include/amazed.h"

void reverse_room_links(room_link_t **list)
{
    room_link_t *tmp = *list;
    room_link_t *prev = NULL;
    room_link_t *next;

    while (tmp != NULL){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *list = prev;
}
