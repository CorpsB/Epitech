/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** event_handler
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static void button_handler(paint_t *paint)
{
    drop_menu_t *tmp_menus;
    button_t *tmp_menu_buttons;
    button_t *tmp_buttons;

    tmp_buttons = paint->buttons;
    while (tmp_buttons != NULL){
        analyze_button(paint, tmp_buttons);
        tmp_buttons = tmp_buttons->next;
    }
    tmp_menus = paint->drop_menus;
    while (tmp_menus != NULL) {
        analyze_menu(paint, tmp_menus);
        tmp_menus = tmp_menus->next;
    }
}

void event_handler(paint_t *paint)
{
    while (sfRenderWindow_pollEvent(paint->window, &paint->event)){
        if (paint->event.type == sfEvtClosed)
            sfRenderWindow_close(paint->window);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            paint_drawing(paint);
        button_handler(paint);
    }
}
