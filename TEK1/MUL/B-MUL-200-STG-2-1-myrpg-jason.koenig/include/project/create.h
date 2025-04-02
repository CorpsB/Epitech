/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** create
*/

#ifndef CREATE_H_
    #define CREATE_H_
    #include "../my.h"

// gui
void init_gui(gui_t *gui, sfRenderWindow *win);

// scene
void create_scene(gui_t *gui, int id,
    int (*update_func)(gui_t *gui), char *back);

// pannel
void create_pannel(pannel_t **list, int id,
    void (*draw_func)(element_t *elt, gui_t *gui),
    void (*destroy_func)(element_t *elt));

//Inventory
void init_inventory(gui_t *gui);
void delete_inv(inventory_t **inv);

// element
void create_data(element_t **list, void *element);

// contructors
void game_scene_constructor(scene_t *scene, gui_t *gui);
void main_menu_constructor(scene_t *scene, gui_t *gui);
void settings_constructor(scene_t *scene, gui_t *gui);
void controls_constructor(scene_t *scene, gui_t *gui);
void fight_constructor(scene_t *scene, gui_t *gui);
void inventory_constructor(scene_t *scene, gui_t *gui);

// functions
csfml_sprite_t *create_csfml_sprite(char *text, sfVector2f *pos,
    sfIntRect *area);
button_t *create_button(char *text, sfVector2f *pos,
    void (*bt_func)(struct button_s *button), button_graphics_shema_t *shema);
dialog_box_t *create_csfml_text(sfVector2f *pos, gui_t *gui,
    unsigned int char_size);
event_entity_t *create_event_entity(void (*evt_fc)(gui_t *, event_entity_t *),
    gui_t *gui, sfVector2f *pos, sfVector2f *size);
dialog_box_t *create_dialog_box(gui_t *gui);
ennemy_t *create_ennemy(gui_t *gui, int id, int lvl);

// pannel objects
void create_button_game_pannel(pannel_t *pannels, gui_t *gui);
void create_button_menu_pannel(pannel_t *pannels, gui_t *gui);
void create_button_setting_pannel(pannel_t *pannels, gui_t *gui);
void create_button_controls_pannel(pannel_t *pannels, gui_t *gui);
void create_button_inventory_pannel(pannel_t *pannels, gui_t *gui);
void create_button_fight_pannel(pannel_t *pannels, gui_t *gui);
void create_map_pannel(pannel_t *pannels, char *map_path, sfVector2f *pos);
void create_map_pannel2(pannel_t *pannels, char *map_path, sfVector2f *pos);
void create_entity_pannel(pannel_t *pannels, gui_t *gui);
void create_event_pannel(pannel_t *pannels, gui_t *gui);

#endif /* !CREATE_H_ */
