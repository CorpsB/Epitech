/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** teleporter
*/

#include "../../../../include/csfml.h"

void teleporter(gui_t *gui, event_entity_t *event)
{
    move_world(gui, 41.6 * 19, -41.6 * 32);
    gui->player.pos_map.x = 21;
    gui->player.pos_map.y = 51;
    gui->player.story_level = 1;
    gui->player.fight_result = LOSE;
}
