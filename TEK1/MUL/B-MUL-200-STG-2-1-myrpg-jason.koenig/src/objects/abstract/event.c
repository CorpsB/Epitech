/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** event
*/

#include "../../../include/csfml.h"

event_entity_t *create_event_entity(void (*evt_fc)(gui_t *, event_entity_t *),
    gui_t *gui, sfVector2f *pos, sfVector2f *size)
{
    event_entity_t *entity = malloc(sizeof(event_entity_t));

    entity->box = sfRectangleShape_create();
    entity->event_func = evt_fc;
    entity->gui = gui;
    entity->state = 1;
    entity->pos.x = pos->x;
    entity->pos.y = pos->y;
    sfRectangleShape_setSize(entity->box, *size);
    sfRectangleShape_setFillColor(entity->box, sfRed);
    sfRectangleShape_setOrigin(entity->box,
        (sfVector2f){sfRectangleShape_getGlobalBounds(entity->box).width / 2,
        sfRectangleShape_getGlobalBounds(entity->box).height / 2});
    sfRectangleShape_setPosition(entity->box, *pos);
    return entity;
}

void draw_event_entity(event_entity_t *entity)
{
    sfRenderWindow_drawRectangleShape(entity->gui->window, entity->box, NULL);
}

void destroy_event_entity(event_entity_t *entity)
{
    sfRectangleShape_destroy(entity->box);
}
