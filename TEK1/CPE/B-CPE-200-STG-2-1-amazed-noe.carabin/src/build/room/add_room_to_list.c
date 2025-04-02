/*
** EPITECH PROJECT, 2024
** CREATE ROOM LIST
** File description:
** Build a list of rooms.
*/

#include "../../../include/amazed.h"

void add_room_to_list(room_list_t **list, char *name, int pos_x, int pos_y)
{
    room_list_t *l_room = malloc(sizeof(room_list_t));

    l_room->name = name;
    l_room->dist = -1;
    l_room->pos_x = pos_x;
    l_room->pos_y = pos_y;
    l_room->robot = NULL;
    l_room->list = NULL;
    l_room->next = *list;
    *list = l_room;
}
