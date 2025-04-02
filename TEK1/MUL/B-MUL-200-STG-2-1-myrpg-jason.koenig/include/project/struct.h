/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <stdbool.h>

enum fight_result {
    WIN,
    LOSE
};

enum scene_type {
    MAIN_MENU,
    GAME_SCENE,
    SETTINGS,
    CONTROLS,
    FIGHT,
    INVENTORY
};

enum pannel_type {
    MAP,
    PLAYER,
    BUTTON,
    ENTITY,
    EVENT
};

enum button_state {
    IDLE,
    HOVER,
    PRESSED
};

enum player_class {
    NOCLASS,
    KNIGHT1,
    KNIGHT2,
    KNIGHT3,
    ASSASSIN1,
    ASSASSIN2,
    ASSASSIN3,
    SWORDSMAN1,
    SWORDSMAN2,
    SWORDSMAN3,
    DARGON_HUNTER1,
    DARGON_HUNTER2,
    DARGON_HUNTER3
};

enum enemy_type {
    MINOTAUR
};

// experience is player experience and also mob drop experience
typedef struct battler_s {
    int level;
    float health;
    float save_health;
    float attack;
    float defense;
    float luck;
    int experience;
} battler_t;

typedef struct item_s {
    sfSprite *sprite;
} item_t;

typedef struct ennemy_s {
    battler_t stats;
    struct csfml_sprite_s *sprite;
    char *name;
} ennemy_t;

typedef struct player_s {
    battler_t stats;
    int fight_result;
    int story_level;
    int energy;
    int utimate_energy;
    char **collision_map;
    sfVector2i pos_map;
    struct element_s *inventory;
    struct event_entity_s *entity;
    struct dialog_box_s *dialog;
    char *name;
    struct csfml_sprite_s *sprite;
} player_t;

typedef struct key_controls_s {
    int mvt_up;
    int mvt_left;
    int mvt_right;
    int mvt_down;
    int interact;
    int act_1;
    int act_2;
    int *last_key;
} key_controls_t;

typedef struct game_graphics_s {
    sfFont *font;
    sfColor idle;
    sfColor hover;
    sfColor clicked;
    sfVector2u win_size;
} game_graphics_t;

typedef struct button_graphic_shema_s {
    sfVector2f size;
    struct gui_s *gui;
} button_graphics_shema_t;

typedef struct dialog_box_s {
    sfBool is_hide;
    sfText *text;
    sfRectangleShape *box;
} dialog_box_t;

typedef struct button_s {
    int button_state;
    void (*bt_func)(struct button_s *);
    sfVector2f pos;
    sfText *text;
    sfRectangleShape *box;
    struct gui_s *gui;
} button_t;

typedef struct csfml_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} csfml_sprite_t;

typedef struct event_entity_s {
    void (*event_func)(struct gui_s *, struct event_entity_s *);
    sfVector2f pos;
    sfRectangleShape *box;
    int state;
    struct gui_s *gui;
} event_entity_t;

typedef struct element_s {
    void *element;
    struct element_s *next;
} element_t;

typedef struct pannel_s {
    int id;
    element_t *element;
    void (*draw_func)(element_t *, struct gui_s *);
    void (*destroy_func)(element_t *);
    struct pannel_s *next;
} pannel_t;

typedef struct scene_s {
    int id;
    int (*update_func)(struct gui_s *);
    pannel_t *pannels;
    element_t *data_list;
    csfml_sprite_t *back;
    struct scene_s *next;
} scene_t;

typedef struct jukebox_s {
    sfMusic *menu;
    sfMusic *fight;
    sfMusic *fallout;
} jukebox_t;

typedef struct inventory_s {
    sfRectangleShape *hitbox;
    sfSprite *item;
    sfTexture *texture;
    bool player_have;
    bool selected;
    struct inventory_s *next;
    int state;
} inventory_t;

typedef struct gui_s {
    sfEvent events;
    bool is_echap;
    pannel_t *event_pannel;
    pannel_t *collision_pannel;
    player_t player;
    sfClock *clock;
    jukebox_t jukebox;
    key_controls_t controls;
    game_graphics_t graphics;
    sfRenderWindow *window;
    scene_t *selected;
    scene_t *scenes;
    inventory_t *inv;
} gui_t;

#endif /* !STRUCT_H_ */
