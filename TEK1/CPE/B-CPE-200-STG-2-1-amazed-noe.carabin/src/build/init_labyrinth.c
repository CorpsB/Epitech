/*
** EPITECH PROJECT, 2024
** INIT
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../include/amazed.h"

void init_labyrinth(labyrinth_t *laby)
{
    laby->nb_robots = -1;
    laby->start = NULL;
    laby->end = NULL;
    laby->rooms = NULL;
    laby->robots = NULL;
    laby->tunnel_count = 0;
}
