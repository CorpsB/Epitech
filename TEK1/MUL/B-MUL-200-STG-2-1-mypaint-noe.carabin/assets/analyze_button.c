/*
** EPITECH PROJECT, 2023
** MUL
** File description:
** analyze_button.c
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static int is_in(paint_t *paint, sfRectangleShape *shape)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2f shape_pos;
    sfVector2f shape_size;

    shape_pos = sfRectangleShape_getPosition(shape);
    shape_size = sfRectangleShape_getSize(shape);
    if ((float)mouse_pos.x >= shape_pos.x * paint->scale.x &&
        (float)mouse_pos.x < (shape_pos.x + shape_size.x) * paint->scale.x &&
        (float)mouse_pos.y >= shape_pos.y * paint->scale.y &&
        (float)mouse_pos.y < (shape_pos.y + shape_size.y) * paint->scale.y)
        return 1;
    return 0;
}

static bool define_button_state_next(paint_t *paint, button_t *button)
{
    if (paint->event.type == sfEvtMouseMoved) {
        if (is_in(paint, button->rect)) {
            button->state = HOVER;
            return false;
        }
    }
    button->state = NONE;
    return false;
}

static bool define_button_state(paint_t *paint, button_t *button)
{
    if (paint->event.type == sfEvtMouseButtonPressed &&
        is_in(paint, button->rect)){
        button->state = SELECTED;
        button->action(paint);
        return false;
    }
    if (paint->event.type == sfEvtMouseButtonReleased &&
        button->state == SELECTED && is_in(paint, button->rect)) {
        button->state = HOVER;
        return true;
    }
    return define_button_state_next(paint, button);
}

void define_button_show(paint_t *paint, button_t *button)
{
    if (button->state == NONE)
        sfRectangleShape_setFillColor(button->rect, GRAY_240);
    if (button->state == HOVER)
        sfRectangleShape_setFillColor(button->rect, GRAY);
    if (button->state == SELECTED)
        sfRectangleShape_setFillColor(button->rect, GRAY_75);
    return;
}

void analyze_button(paint_t *paint, button_t *button)
{
    if (define_button_state(paint, button)){
        button->action(paint);
    }
    define_button_show(paint, button);
}
