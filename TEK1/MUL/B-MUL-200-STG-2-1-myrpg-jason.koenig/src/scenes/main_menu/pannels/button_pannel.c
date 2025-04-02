/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

void create_button_menu_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("PLAY", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 6 * 1},
    &btn_play, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("LOAD", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 6 * 2},
    &btn_load, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("SETTINGS", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 6 * 3},
    &btn_settings, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("EXIT", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 6 * 4},
    &btn_exit, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
}
