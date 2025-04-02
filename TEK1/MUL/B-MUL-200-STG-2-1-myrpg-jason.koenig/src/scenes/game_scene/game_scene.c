/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** game_scene
*/

#include "../../../include/csfml.h"

void game_scene_constructor(scene_t *scene, gui_t *gui)
{
    gui->player.inventory = scene->data_list;
    create_pannel(&scene->pannels, BUTTON, &draw_esc_pannel,
        &destroy_button_pannel);
    create_button_game_pannel(scene->pannels, gui);
    create_pannel(&scene->pannels, EVENT, &draw_event_pannel,
        &destroy_event_pannel);
    create_event_pannel(scene->pannels, gui);
    gui->event_pannel = scene->pannels;
    create_pannel(&scene->pannels, MAP, &draw_map_pannel, &destroy_map_pannel);
    create_map_pannel2(scene->pannels, "assets/maps/main_shelter.png",
    &(sfVector2f){gui->graphics.win_size.x / 2, gui->graphics.win_size.y / 2});
    gui->collision_pannel = scene->pannels;
    create_pannel(&scene->pannels, ENTITY, &draw_entity_pannel,
        &destroy_map_pannel);
    create_entity_pannel(scene->pannels, gui);
    create_pannel(&scene->pannels, MAP, &draw_map_pannel, &destroy_map_pannel);
    create_map_pannel(scene->pannels, "assets/maps/main_shelter.png",
    &(sfVector2f){gui->graphics.win_size.x / 2, gui->graphics.win_size.y / 2});
}

int game_scene_update(gui_t *gui)
{
    update_event_pannel(gui->event_pannel->element, gui);
    draw_pannels(gui->selected->pannels, gui);
    if (gui->events.key.code == sfKeyEscape){
        gui->player.dialog->is_hide = sfTrue;
        gui->is_echap = true;
    }
    draw_dialog(gui->player.dialog, gui->window);
    return 0;
}
