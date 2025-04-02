/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** buttons_actions
*/

#include "../includes/my.h"
#include "../includes/paint.h"

void save_image(paint_t *paint)
{
    sfImage_saveToFile(paint->image, "my_paint_image.jpg");
}

void exit_paint(paint_t *paint)
{
    sfRenderWindow_close(paint->window);
}

void default_color(paint_t *paint)
{
    paint->selected_color = sfBlack;
}

void no_action(paint_t *paint)
{
    ;
}
