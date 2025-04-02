/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

void create_button_game_pannel_next(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("RESUME", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 6},
    &btn_game, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("INVENTORY", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 5},
    &btn_inventory, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
}

void create_button_game_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("MENU", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7},
    &btn_menu, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("SAVE", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 2},
    &btn_save, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
            create_data(&pannels->element,
    create_button("LOAD", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 3},
    &btn_save, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
            create_data(&pannels->element,
    create_button("SETTINGS", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 4},
    &btn_settings, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
    create_button_game_pannel_next(pannels, gui);
}

void draw_esc_pannel(element_t *elt, gui_t *gui)
{
    button_t *target;

    if (gui->is_echap == false)
        return;
    for (element_t *tmp = elt; tmp != NULL; tmp = tmp->next){
        target = tmp->element;
        draw_button(target);
    }
}
