/*
** EPITECH PROJECT, 2024
** SORT LINKS
** File description:
** Find the smallest.
*/

#include "../include/amazed.h"

void sort_links(labyrinth_t *laby)
{
    room_list_t *room = laby->rooms;

    for (; room != NULL; room = room->next)
        room->list = sort_room_list(room->list);
}
