/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_state
*/

#include "../../include/csfml.h"

static void color_btn(button_t *bt, int state)
{
    if (state == HOVER)
        sfRectangleShape_setFillColor(bt->box, bt->gui->graphics.hover);
    if (state == PRESSED)
        sfRectangleShape_setFillColor(bt->box, bt->gui->graphics.clicked);
    if (state == IDLE)
        sfRectangleShape_setFillColor(bt->box, bt->gui->graphics.idle);
    bt->button_state = state;
}

void button_state(button_t *bt)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(bt->gui->window);
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(bt->box);

    if (sfFloatRect_contains(&hitbox, (float)mouse.x, (float)mouse.y)) {
        if (bt->button_state == IDLE)
            color_btn(bt, HOVER);
        if (bt->gui->events.type == sfEvtMouseButtonPressed)
            color_btn(bt, PRESSED);
        if (bt->gui->events.type == sfEvtMouseButtonReleased &&
        bt->button_state == PRESSED) {
            bt->bt_func(bt);
            bt->button_state = IDLE;
        }
    } else
        color_btn(bt, IDLE);
}
