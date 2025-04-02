/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** draw
*/

#include "../includes/my.h"
#include "../includes/paint.h"

void draw_buttons(paint_t *paint)
{
    button_t *tmp;

    tmp = paint->buttons;
    while (tmp != NULL){
        sfRenderWindow_drawRectangleShape(paint->window, tmp->rect, NULL);
        sfRenderWindow_drawText(paint->window, tmp->text, NULL);
        tmp = tmp->next;
    }
}

void draw_drop(drop_menu_t *menu, paint_t *paint)
{
    button_t *button = menu->buttons;
    sfVector2f pos;

    for (; button != NULL; button = button->next) {
        pos = sfRectangleShape_getPosition(button->rect);
        sfRenderWindow_drawRectangleShape(paint->window, button->rect, NULL);
        sfRenderWindow_drawText(paint->window, button->text, NULL);
        button->state = 0;
    }
}

void draw_drop_menus(paint_t *paint)
{
    drop_menu_t *tmp = paint->drop_menus;

    while (tmp != NULL){
        sfRenderWindow_drawRectangleShape(paint->window, tmp->rect, NULL);
        sfRenderWindow_drawText(paint->window, tmp->text, NULL);
        if (tmp->state == 4)
            draw_drop(tmp, paint);
        tmp = tmp->next;
    }
}
