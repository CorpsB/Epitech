/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** destroy
*/

#ifndef DESTROY_H_
    #define DESTROY_H_
    #include "../my.h"

// gui
void destroy_gui(gui_t *gui, sfBool clean_all);

// scene
void destroy_scenes(scene_t **list);

// pannel
void destroy_pannels(pannel_t **list);

// element
void destroy_data_list(element_t **list);

// functions
void destroy_csfml_sprite(csfml_sprite_t *sprite);
void destroy_button(button_t *button);
void destroy_dialog(dialog_box_t *box);
void destroy_event_entity(event_entity_t *entity);

// pannel objects
void destroy_map_pannel(element_t *elt);
void destroy_button_pannel(element_t *elt);
void destroy_event_pannel(element_t *elt);

#endif /* !DESTROY_H_ */
