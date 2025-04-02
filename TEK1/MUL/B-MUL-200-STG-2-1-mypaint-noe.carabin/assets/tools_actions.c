/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** tools_actions
*/

#include "../includes/my.h"
#include "../includes/paint.h"

void eraser_action(paint_t *paint)
{
    paint->tool = 1;
    paint->selected_color = sfWhite;
}

void pen_action(paint_t *paint)
{
    if (paint->tool == 1)
        paint->selected_color = sfBlack;
    paint->tool = 0;
}
