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

static void set_menu_state_next(paint_t *paint, drop_menu_t *menu)
{
    if (paint->event.type == sfEvtMouseMoved && menu->state != OPEN) {
        if (is_in(paint, menu->rect)){
            menu->state = HOVER;
            return;
        }
    }
    if (menu->state != OPEN)
        menu->state = NONE;
    return;
}

//Gestion de son état
static void set_menu_state(paint_t *paint, drop_menu_t *menu)
{
    if (paint->event.type == sfEvtMouseButtonPressed && menu->state == OPEN) {
        menu->state = NONE;
        return;
    }
    if (paint->event.type == sfEvtMouseButtonReleased &&
        menu->state == SELECTED) {
        menu->state = OPEN;
        return;
    }
    if (paint->event.type == sfEvtMouseButtonPressed &&
        menu->state == HOVER && menu->state != OPEN) {
        menu->state = SELECTED;
        return;
    }
    set_menu_state_next(paint, menu);
    return;
}

//Impresion
void show_drop_menu(paint_t *paint, drop_menu_t *menu)
{
    if (menu->state == NONE)
        sfRectangleShape_setFillColor(menu->rect, GRAY_240);
    if (menu->state == HOVER)
        sfRectangleShape_setFillColor(menu->rect, GRAY);
    if (menu->state == SELECTED || menu->state == OPEN)
        sfRectangleShape_setFillColor(menu->rect, GRAY_75);
    return;
}

//Gestion intégrale d'un drop menu
void analyze_menu(paint_t *paint, drop_menu_t *menu)
{
    button_t *tmp = menu->buttons;

    if (menu->state == OPEN) {
        for (; menu->buttons != NULL; menu->buttons = menu->buttons->next) {
            analyze_button(paint, menu->buttons);
        }
    }
    menu->buttons = tmp;
    set_menu_state(paint, menu);
    show_drop_menu(paint, menu);
}
