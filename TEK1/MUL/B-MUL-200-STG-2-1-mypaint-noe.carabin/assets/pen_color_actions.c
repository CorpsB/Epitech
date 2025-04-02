/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** buttons_actions
*/

#include "../includes/my.h"
#include "../includes/paint.h"

void color_red(paint_t *paint)
{
    if (paint->tool == 0)
        paint->selected_color = sfRed;
}

void color_blue(paint_t *paint)
{
    if (paint->tool == 0)
        paint->selected_color = sfBlue;
}

void color_yellow(paint_t *paint)
{
    if (paint->tool == 0)
        paint->selected_color = sfYellow;
}

void color_green(paint_t *paint)
{
    if (paint->tool == 0)
        paint->selected_color = sfGreen;
}

void color_purple(paint_t *paint)
{
    if (paint->tool == 0)
        paint->selected_color = PURPLE;
}
