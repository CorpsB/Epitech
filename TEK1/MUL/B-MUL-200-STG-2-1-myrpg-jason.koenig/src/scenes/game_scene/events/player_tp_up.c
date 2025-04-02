/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** player_tp_up
*/

#include "../../../../include/csfml.h"

void player_tp_up(gui_t *gui, event_entity_t *event)
{
    gui->player.pos_map.y -= 3;
    move_world(gui, 0, 166.4f);
}
