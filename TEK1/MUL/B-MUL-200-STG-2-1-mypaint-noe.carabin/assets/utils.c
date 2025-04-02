/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** utils
*/

#include "../includes/my.h"
#include "../includes/paint.h"

sfVector2f center_element_to_window(paint_t *paint, sfVector2f size)
{
    sfVector2f position;
    sfVector2u window_size;

    window_size = sfRenderWindow_getSize(paint->window);
    position.x = (window_size.x - size.x) / 2.0f;
    position.y = (window_size.y - size.y) / 2.0f;
    return position;
}

sfVector2f get_center_of_text(sfText *text)
{
    sfVector2f position;
    sfFloatRect textRect;

    textRect = sfText_getGlobalBounds(text);
    position.x = textRect.width / 2.0f;
    position.y = textRect.height / 2.0f;
    return position;
}

sfVector2f get_center_of_menu(rect_t rect_stat)
{
    sfVector2f position;
    sfVector2f menu_position;
    sfVector2f menu_size;

    menu_position = rect_stat.position;
    menu_size = rect_stat.size;
    position.x = (menu_size.x / 2.0f) + menu_position.x;
    position.y = (menu_size.y / 2.0f) + menu_position.y;
    return position;
}

sfVector2f get_window_scale(paint_t *paint)
{
    sfVector2f scale;
    sfVector2u window_size = sfRenderWindow_getSize(paint->window);

    scale.x = window_size.x / (float)paint->videoMode.width;
    scale.y = window_size.y / (float)paint->videoMode.height;
    return scale;
}
