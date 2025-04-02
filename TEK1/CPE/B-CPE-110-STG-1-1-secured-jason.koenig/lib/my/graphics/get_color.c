/*
** EPITECH PROJECT, 2023
** GET_COLOR
** File description:
** Return the color using bit shifting.
*/

#include "../../../include/my.h"
int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color_value = 0;

    color_value += red;
    color_value = color_value << 8;
    color_value += green;
    color_value = color_value << 8;
    color_value += blue;
    return (color_value);
}
