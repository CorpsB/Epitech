/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** history_1
*/

#include "../../../../include/csfml.h"

void history_3(gui_t *gui)
{
    if (gui->player.story_level != 1)
        return;
    gui->player.entity->state = 30;
    story_tell(gui, gui->player.entity);
    gui->player.story_level = 2;
}
