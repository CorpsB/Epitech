/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** player_npc_1
*/

#include "../../../../include/csfml.h"

void player_npc_4(gui_t *gui, event_entity_t *event)
{
    if (event->state == 1){
        if (gui->player.entity->state == 0){
            gui->player.entity->state = 43;
            event->state = 0;
        }
        story_tell(gui, gui->player.entity);
        if (gui->player.story_level == 1)
            start_fight(gui, MINOTAUR, 4);
    }
}
