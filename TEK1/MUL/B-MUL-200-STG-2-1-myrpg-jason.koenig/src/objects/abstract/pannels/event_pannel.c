/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** event_pannel
*/

#include "../../../../include/csfml.h"

void draw_event_pannel(element_t *elt, gui_t *gui)
{
    event_entity_t *target;

    return;
    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        sfRenderWindow_drawRectangleShape(gui->window, target->box, NULL);
    }
}

void update_event_pannel(element_t *elt, gui_t *gui)
{
    event_entity_t *target;
    sfBool result;
    int sum = 0;

    for (element_t *tmp = elt; tmp != NULL; tmp = tmp->next){
        target = tmp->element;
        result = is_rectangle_collision(gui->player.entity->box, target->box);
        if (!result)
            continue;
        ++sum;
        if (target->state != 0 && target->state != 99 ||
        target->event_func == player_move_event)
            target->event_func(gui, target);
    }
    if (sum == 1)
        reset_event_pannel(elt, gui);
}

void reset_event_pannel(element_t *elt, gui_t *gui)
{
    event_entity_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        if (target->state == 0 && target->event_func != player_move_event)
            target->state = 1;
    }
}

void move_event_pannel(element_t *elt, float pos_x, float pos_y)
{
    event_entity_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        if (target->event_func == player_move_event)
            continue;
        target->pos.x += pos_x;
        target->pos.y += pos_y;
        sfRectangleShape_setPosition(target->box, target->pos);
    }
}

void destroy_event_pannel(element_t *elt)
{
    event_entity_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        sfRectangleShape_destroy(target->box);
    }
}
