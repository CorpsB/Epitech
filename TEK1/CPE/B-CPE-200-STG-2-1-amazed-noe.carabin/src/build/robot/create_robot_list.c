/*
** EPITECH PROJECT, 2024
** CREATE ROBOT LIST
** File description:
** Build a list of robots with the number of it.
*/

#include "../../../include/amazed.h"

robot_list_t *create_robot_list(labyrinth_t *laby)
{
    robot_list_t *list = NULL;

    for (int i = laby->nb_robots; i > 0; --i)
        add_robot_to_list(&list, i, laby->start);
    return list;
}
