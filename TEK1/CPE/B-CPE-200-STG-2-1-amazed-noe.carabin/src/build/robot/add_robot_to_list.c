/*
** EPITECH PROJECT, 2024
** CREATE ROBOT LIST
** File description:
** Build a list of robots with the number of it.
*/

#include "../../../include/amazed.h"

void add_robot_to_list(robot_list_t **list, int id, room_list_t *start)
{
    robot_list_t *l_robot = malloc(sizeof(robot_list_t));

    l_robot->id = id;
    l_robot->room = start;
    l_robot->next = *list;
    *list = l_robot;
}
