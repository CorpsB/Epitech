/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

static void create_button_setting_pannel_next(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("FULL SCREEN", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 8 * 5},
    &btn_fullscreen, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("CONTROLS", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 8 * 6},
    &btn_controls, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("BACK TO MENU", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 8 * 7},
    &btn_menu, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
}

void create_button_setting_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("+", &(sfVector2f){gui->graphics.win_size.x / 4,
    gui->graphics.win_size.y / 8 * 2},
    &btn_more, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("-", &(sfVector2f){gui->graphics.win_size.x / 4 * 3,
    gui->graphics.win_size.y / 8 * 2},
    &btn_less, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("1920 x 1080", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 8 * 3},
    &btn_res1, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
        create_data(&pannels->element,
    create_button("1366 x 768", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 8 * 4},
    &btn_res2, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
    create_button_setting_pannel_next(pannels, gui);
}
