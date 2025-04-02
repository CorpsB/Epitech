/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** update
*/

#ifndef UPDATE_H_
    #define UPDATE_H_
    #include "../my.h"

// gui
int update_gui(gui_t *gui);

// scene
int game_scene_update(gui_t *gui);
int main_menu_update(gui_t *gui);
int settings_update(gui_t *gui);
int controls_update(gui_t *gui);
int fight_update(gui_t *gui);
int inventory_update(gui_t *gui);

// pannel
void update_event_pannel(element_t *elt, gui_t *gui);

// buttons
void btn_menu(button_t *button); // GameScene
void btn_save(button_t *button);
void btn_game(button_t *button);
void btn_inventory(button_t *button);
void btn_exit(button_t *button); // MainMenu
void btn_play(button_t *button);
void btn_load(button_t *button);
void btn_settings(button_t *button);
void btn_controls(button_t *button); // Settings
void btn_fullscreen(button_t *button);
void btn_less(button_t *button);
void btn_more(button_t *button);
void btn_res1(button_t *button);
void btn_res2(button_t *button);
void btn_act1(button_t *butttton); //Controls
void btn_act2(button_t *butttton);
void btn_back(button_t *butttton);
void btn_for(button_t *butttton);
void btn_int(button_t *butttton);
void btn_left(button_t *butttton);
void btn_right(button_t *butttton);
void btn_normal_attack(button_t *button);
void btn_skill_attack(button_t *button);
void btn_ultimate_attack(button_t *button);
int get_key(button_t *button);

// move functions
void move_map_pannel(element_t *elt, float pos_x, float pos_y);
void move_event_pannel(element_t *elt, float pos_x, float pos_y);
void move_entity_pannel(element_t *elt, float pos_x, float pos_y);

// functions
void button_state(button_t *button);

// events
void player_move_event(gui_t *gui, event_entity_t *event);
void player_tp_up(gui_t *gui, event_entity_t *event);
void player_tp_down(gui_t *gui, event_entity_t *event);
void player_npc_1(gui_t *gui, event_entity_t *event);
void player_npc_2(gui_t *gui, event_entity_t *event);
void player_npc_3(gui_t *gui, event_entity_t *event);
void player_npc_4(gui_t *gui, event_entity_t *event);
void player_npc_5(gui_t *gui, event_entity_t *event);
void history_1(gui_t *gui, event_entity_t *event);
void history_2(gui_t *gui, event_entity_t *event);

// classes
void become_knight(battler_t *stats, int id);
void become_assassin(battler_t *stats, int id);
void become_swordsman(battler_t *stats, int id);
void become_dragon_hunter(battler_t *stats, int id);

#endif /* !UPDATE_H_ */
