/*
** EPITECH PROJECT, 2024
** CREATE ROBOT LIST
** File description:
** Build a list of robots with the number of it.
*/

#include "../../../include/amazed.h"

void free_robot_list(robot_list_t **list)
{
    robot_list_t *target;
    robot_list_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}
