/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** game_scene
*/

#include "../../../include/csfml.h"

void inventory_constructor(scene_t *scene, gui_t *gui)
{
    create_pannel(&scene->pannels, BUTTON, &draw_button_pannel,
        &destroy_button_pannel);
    create_button_inventory_pannel(scene->pannels, gui);
}

void draw_inv(gui_t *gui)
{
    inventory_t *tmp = gui->inv;

    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawRectangleShape(gui->window, tmp->hitbox, NULL);
        sfRenderWindow_drawSprite(gui->window, tmp->item, NULL);
    }
}

int inventory_update(gui_t *gui)
{
    draw_pannels(gui->selected->pannels, gui);
    draw_inv(gui);
    return 0;
}
