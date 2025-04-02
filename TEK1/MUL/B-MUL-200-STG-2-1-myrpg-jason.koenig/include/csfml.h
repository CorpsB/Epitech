/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** List of functions avaliable in lib/my/
*/

#ifndef MY_CSFML
    #define MY_CSFML
    #include "project/create.h"
    #include "project/destroy.h"
    #include "project/update.h"
    #include "project/draw.h"
    #include "project/save.h"

int menu(sfRenderWindow *window);
scene_t *select_scene(gui_t *gui, int id);
void move_world(gui_t *gui, float pos_x, float pos_y);
void set_dialog_text(dialog_box_t *dialog, char *text);
sfBool is_rectangle_collision(sfRectangleShape* rect1,
    sfRectangleShape* rect2);
sfBool is_collision_map(player_t *player, int x, int y);
void story_tell(gui_t *gui, event_entity_t *event);
void start_fight(gui_t *gui, int ennemi, int lvl);
void end_fight(gui_t *gui);
void reset_event_pannel(element_t *elt, gui_t *gui);
void anim_player(gui_t *gui, int state, float ac_time);

#endif
