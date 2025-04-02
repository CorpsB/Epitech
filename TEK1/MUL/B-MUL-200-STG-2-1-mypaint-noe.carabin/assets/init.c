/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** init
*/

#include "../includes/paint.h"

static void init_buttons_from_menu(paint_t *paint)
{
    add_button_to_menu(paint, (rect_t){"Save", {0, 26}, {130, 26}, GRAY},
        0, save_image);
    add_button_to_menu(paint, (rect_t){"Exit", {0, 52}, {130, 26}, GRAY},
        0, exit_paint);
    add_button_to_menu(paint, (rect_t){"Pen", {130, 26}, {130, 26}, GRAY},
        1, pen_action);
    add_button_to_menu(paint, (rect_t){"Eraser", {130, 52}, {130, 26}, GRAY},
        1, eraser_action);
    add_button_to_menu(paint, (rect_t){"About", {260, 26}, {130, 26}, GRAY},
        2, no_action);
}

void init_drop_menus(paint_t *paint)
{
    add_drop_menu(paint, (rect_t){"File", {0, 0}, {130, 26}, GRAY}, 0);
    add_drop_menu(paint, (rect_t){"Edit", {130, 0}, {130, 26}, GRAY}, 1);
    add_drop_menu(paint, (rect_t){"Help", {260, 0}, {130, 26}, GRAY}, 2);
    init_buttons_from_menu(paint);
}

void init_buttons(paint_t *paint)
{
    add_button(paint, (rect_t){"Red", {10, 140}, {80, 80}, GRAY}, color_red);
    add_button(paint, (rect_t){"Blue", {10, 235}, {80, 80}, GRAY}, color_blue);
    add_button(paint, (rect_t){"Yellow", {10, 330}, {80, 80}, GRAY},
        color_yellow);
    add_button(paint, (rect_t){"Green", {10, 425}, {80, 80}, GRAY},
        color_green);
    add_button(paint, (rect_t){"Purple", {10, 520}, {80, 80}, GRAY},
        color_purple);
    add_button(paint, (rect_t){"Black", {10, 615}, {80, 80}, GRAY},
        default_color);
    add_button(paint, (rect_t){"10", {100, 140}, {80, 80}, GRAY}, size_10);
    add_button(paint, (rect_t){"20", {100, 235}, {80, 80}, GRAY}, size_20);
    add_button(paint, (rect_t){"30", {100, 330}, {80, 80}, GRAY}, size_30);
    add_button(paint, (rect_t){"40", {100, 425}, {80, 80}, GRAY}, size_40);
    add_button(paint, (rect_t){"50", {100, 520}, {80, 80}, GRAY}, size_50);
}
