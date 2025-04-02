/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** history_1
*/

#include "../../../../include/csfml.h"

void history_1(gui_t *gui, event_entity_t *event)
{
    if (event->state == 1){
        if (gui->player.entity->state == 0){
            gui->player.entity->state = 12;
            event->state = 99;
        }
        story_tell(gui, gui->player.entity);
    }
}
