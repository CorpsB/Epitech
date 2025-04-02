/*
** EPITECH PROJECT, 2023
** EVENT HANDLER
** File description:
** Do event things.
*/

#include "../include/csfml.h"

void analyse_events(gui_t *gui)
{
    if (gui->events.type == sfEvtClosed)
        sfRenderWindow_close(gui->window);
    if (gui->events.type == sfEvtKeyPressed){
        if (gui->events.key.code == gui->controls.mvt_up)
            gui->controls.last_key = &gui->controls.mvt_up;
        if (gui->events.key.code == gui->controls.mvt_down)
            gui->controls.last_key = &gui->controls.mvt_down;
        if (gui->events.key.code == gui->controls.mvt_left)
            gui->controls.last_key = &gui->controls.mvt_left;
        if (gui->events.key.code == gui->controls.mvt_right)
            gui->controls.last_key = &gui->controls.mvt_right;
        if (gui->events.key.code == gui->controls.interact)
            gui->controls.last_key = &gui->controls.interact;
        if (gui->events.key.code == gui->controls.act_1)
            gui->controls.last_key = &gui->controls.act_1;
        if (gui->events.key.code == gui->controls.act_2)
            gui->controls.last_key = &gui->controls.act_2;
    }
}
