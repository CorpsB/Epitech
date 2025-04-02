/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** game_scene
*/

#include "../../../include/csfml.h"

void settings_constructor(scene_t *scene, gui_t *gui)
{
    create_pannel(&scene->pannels, BUTTON, &draw_button_pannel,
        &destroy_button_pannel);
    create_button_setting_pannel(scene->pannels, gui);
}

int settings_update(gui_t *gui)
{
    draw_pannels(gui->selected->pannels, gui);
    return 0;
}
