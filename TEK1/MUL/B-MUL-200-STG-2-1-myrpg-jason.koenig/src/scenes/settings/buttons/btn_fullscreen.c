/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_fullscreen.c
*/

#include "../../../../include/csfml.h"

void btn_fullscreen(button_t *button)
{
    sfVideoMode mode = {sfVideoMode_getDesktopMode().width,
        sfVideoMode_getDesktopMode().height, 32};
    sfRenderWindow *window;
    sfRenderWindow *tmp;

    tmp = button->gui->window;
    window = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    button->gui->window = window;
    sfRenderWindow_destroy(tmp);
    destroy_gui(button->gui, sfFalse);
    menu(window);
    exit(0);
}
