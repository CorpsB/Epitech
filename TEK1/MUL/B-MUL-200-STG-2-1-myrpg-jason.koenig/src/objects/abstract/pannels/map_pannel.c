/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** map_pannel
*/

#include "../../../../include/csfml.h"

void draw_entity_pannel(element_t *elt, gui_t *gui)
{
    csfml_sprite_t *target;

    for (element_t *tmp = elt; tmp != NULL; tmp = tmp->next){
        target = tmp->element;
        sfRenderWindow_drawSprite(gui->window, target->sprite, NULL);
    }
}

// if (elt->next != NULL){
//         target = elt->next->element;
//         sfRenderWindow_drawSprite(win, target->sprite, NULL);
//     }
void draw_map_pannel(element_t *elt, gui_t *gui)
{
    csfml_sprite_t *target = elt->element;

    sfRenderWindow_drawSprite(gui->window, target->sprite, NULL);
}

void move_map_pannel(element_t *elt, float pos_x, float pos_y)
{
    csfml_sprite_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        target->pos.x += pos_x;
        target->pos.y += pos_y;
        sfSprite_setPosition(target->sprite, target->pos);
    }
}

void destroy_map_pannel(element_t *elt)
{
    csfml_sprite_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        destroy_csfml_sprite(target);
    }
}
