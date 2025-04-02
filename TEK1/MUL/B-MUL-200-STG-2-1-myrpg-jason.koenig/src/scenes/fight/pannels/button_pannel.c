/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button_pannel
*/

#include "../../../../include/csfml.h"

void create_button_fight_pannel(pannel_t *pannels, gui_t *gui)
{
        create_data(&pannels->element,
    create_button("Sword Stroke",
    &(sfVector2f){140, gui->graphics.win_size.y - 57.5},
    &btn_normal_attack,
    &(button_graphics_shema_t){(sfVector2f){240, 75}, gui}));
        create_data(&pannels->element,
    create_button("Fire blade",
    &(sfVector2f){140, gui->graphics.win_size.y - 57.5 - 95},
    &btn_skill_attack,
    &(button_graphics_shema_t){(sfVector2f){240, 75}, gui}));
        create_data(&pannels->element,
    create_button("Reinforcement",
    &(sfVector2f){140, gui->graphics.win_size.y - 57.5 - 95 * 2},
    &btn_ultimate_attack,
    &(button_graphics_shema_t){(sfVector2f){240, 75}, gui}));
}

void draw_button_fight_pannel(element_t *elt, gui_t *gui)
{
    button_t *target;

    for (element_t *tmp = elt; tmp != NULL; tmp = tmp->next){
        target = tmp->element;
        if (target->bt_func == btn_skill_attack && gui->player.energy > 2)
            draw_button(target);
        if (target->bt_func == btn_normal_attack)
            draw_button(target);
        if (target->bt_func == btn_ultimate_attack &&
        gui->player.utimate_energy == 100)
            draw_button(target);
    }
}
