/*
** EPITECH PROJECT, 2024
** CREATE ROOM LIST
** File description:
** Build a list of rooms.
*/

#include "../../../include/amazed.h"

void add_room_link(room_list_t *l1, room_list_t *l2)
{
    room_link_t *l_link1 = malloc(sizeof(room_link_t));
    room_link_t *l_link2;

    l_link1->room = l2;
    l_link1->next = l1->list;
    l1->list = l_link1;
    if (l1 != l2){
        l_link2 = malloc(sizeof(room_link_t));
        l_link2->room = l1;
        l_link2->next = l2->list;
        l2->list = l_link2;
    }
}
