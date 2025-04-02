/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-noe.carabin
** File description:
** counter.c
*/

#include "../include/amazed.h"

void assign_room_dist(room_link_t *actual, int counter)
{
    for (; actual != NULL; actual = actual->next){
        if (actual->room->dist != -1 && counter >= actual->room->dist)
            continue;
        actual->room->dist = counter + 1;
        assign_room_dist(actual->room->list, counter + 1);
    }
}

void counter(labyrinth_t *laby)
{
    room_link_t *link = laby->end->list;

    laby->end->dist = 0;
    assign_room_dist(link, 0);
}
