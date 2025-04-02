/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

static void create_button_controls_pannel_next(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("ACTION 2", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 5},
    &btn_act2, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("INTERACTION", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 6},
    &btn_int, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("FORWARD", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 1},
    &btn_for, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("BACK TO SETTINGS",
    &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 7},
    &btn_settings, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
}

void create_button_controls_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("LEFT", &(sfVector2f){gui->graphics.win_size.x / 4,
    gui->graphics.win_size.y / 9 * 2},
    &btn_left, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("RIGHT", &(sfVector2f){gui->graphics.win_size.x / 4 * 3,
    gui->graphics.win_size.y / 9 * 2},
    &btn_right, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("BACKWARD", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 3},
    &btn_back, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("ACTION 1", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 9 * 4},
    &btn_act1, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
    create_button_controls_pannel_next(pannels, gui);
}
