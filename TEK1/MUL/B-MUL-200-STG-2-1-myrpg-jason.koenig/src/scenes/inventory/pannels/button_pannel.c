/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

void create_button_inventory_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("RESUME", &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 7 * 6},
    &btn_play, &(button_graphics_shema_t){(sfVector2f){300, 100}, gui}));
}
