/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_action1.c
*/

#include "../../../../include/csfml.h"

int get_key(button_t *button)
{
    while (1) {
        sfRenderWindow_waitEvent(button->gui->window, &button->gui->events);
        if (button->gui->events.type == sfEvtKeyPressed)
            break;
    }
    return button->gui->events.key.code;
}

void btn_act1(button_t *butttton)
{
    butttton->gui->controls.act_1 = get_key(butttton);
}
