/*
** EPITECH PROJECT, 2024
** ROBOTS
** File description:
** Do you know how robots can be fast ?
*/

#include "../include/amazed.h"

void robot_switch_room(robot_list_t *robot, room_list_t *next, int cpt)
{
    robot->room->robot = NULL;
    robot->room = next;
    next->robot = robot;
    if (cpt > 0)
        my_putchar(' ', 1);
    my_putchar('P', 1);
    my_putnbr(robot->id, 1);
    my_putchar('-', 1);
    my_putstr(next->name, 1);
}

// Affiner avec l'id
static void find_next_room(robot_list_t *robot, labyrinth_t *laby,
    int cpt)
{
    room_link_t *tmp = robot->room->list;

    if (tmp->room->robot == NULL || tmp->room == laby->end)
        return robot_switch_room(robot, tmp->room, cpt);
    for (tmp = tmp->next; tmp != NULL; tmp = tmp->next){
        if (tmp->room->dist > laby->nb_robots)
            break;
        if (tmp->room->robot == NULL || tmp->room == laby->end)
            return robot_switch_room(robot, tmp->room, cpt);
    }
}

int move_robots(labyrinth_t *laby)
{
    robot_list_t *robots = laby->robots;
    int cpt = 0;

    for (; robots != NULL; robots = robots->next)
        if (robots->room != laby->end){
            find_next_room(robots, laby, cpt);
            ++cpt;
        }
    if (cpt > 0){
        my_putchar('\n', 1);
        return 1;
    }
    return 0;
}
