/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_resolution2.c
*/

#include "../../../../include/csfml.h"

void btn_res2(button_t *button)
{
    sfVideoMode mode = {1366, 768, 32};
    sfRenderWindow *window;
    sfRenderWindow *tmp;

    tmp = button->gui->window;
    window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    button->gui->window = window;
    sfRenderWindow_destroy(tmp);
    destroy_gui(button->gui, sfFalse);
    menu(window);
    exit(0);
}
