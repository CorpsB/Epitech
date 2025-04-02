/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** draw
*/

#ifndef DRAW_H_
    #define DRAW_H_
    #include "../my.h"

// pannel
void draw_pannels(pannel_t *list, gui_t *gui);

// objects
void draw_button(button_t *button);
void draw_event_entity(event_entity_t *entity);
void draw_dialog(dialog_box_t *box, sfRenderWindow *win);

// pannel objects
void draw_map_pannel(element_t *elt, gui_t *gui);
void draw_button_pannel(element_t *elt, gui_t *gui);
void draw_entity_pannel(element_t *elt, gui_t *gui);
void draw_event_pannel(element_t *elt, gui_t *gui);
void draw_esc_pannel(element_t *elt, gui_t *gui);
void draw_button_fight_pannel(element_t *elt, gui_t *gui);
void teleporter(gui_t *gui, event_entity_t *event);
void history_3(gui_t *gui);

#endif /* !DRAW_H_ */
