/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    #include "csfml.h"

    #define BLACK sfColor_fromRGB(0, 0, 0)
    #define GRAY sfColor_fromRGB(128, 128, 128)
    #define WHITE sfColor_fromRGB(255, 255, 255)
    #define GRAY_75 sfColor_fromRGB(75, 75, 75)
    #define GRAY_240 sfColor_fromRGB(240, 240, 240)
    #define GRAY_220 sfColor_fromRGB(220, 220, 220)
    #define PURPLE sfColor_fromRGB(255, 0, 255)

//Structure locker button
typedef struct global_struct {
    int locker;
} global_t;

typedef struct {
    char *text;
    sfVector2f position;
    sfVector2f size;
    sfColor color;
} rect_t;

typedef struct paint_s paint_t;

typedef struct button_s {
    int state;
    sfText *text;
    sfRectangleShape *rect;
    void (*action)(paint_t *);
    struct button_s *next;
} button_t;

typedef struct drop_menu_s {
    int state;
    int id;
    char *str;
    sfRectangleShape *rect;
    sfText *text;
    button_t *buttons;
    struct drop_menu_s *next;
} drop_menu_t;

typedef struct paint_s {
    sfVector2f scale;
    sfRenderWindow *window;
    sfVideoMode videoMode;
    sfEvent event;
    sfMusic *music;
    button_t *buttons;
    drop_menu_t *drop_menus;
    sfImage *image;
    sfSprite *image_sprite;
    sfTexture *image_texture;
    sfFont *font;
    int tool;
    int pen_size;
    sfColor selected_color;
} paint_t;

// Paint drawing
void paint_drawing(paint_t *paint);

// Init
void init_drop_menus(paint_t *paint);
void init_buttons(paint_t *paint);

// Assets (Main)
void event_handler(paint_t *paint);
void draw_paint(paint_t *paint);
void destroy_paint(paint_t *paint);
void init_paint(paint_t *paint, int is_from_file, char *pathname);
void music_manager(paint_t *paint);

// Assets (Menu)
void add_drop_menu(paint_t *paint, rect_t rect_stat, int id);
void free_drop_menus(paint_t *paint);

// Assets (Button)
void add_button_to_menu(paint_t *paint, rect_t rect_stat,
    int menu_id, void (*action)(struct paint_s *));
void add_button(paint_t *paint, rect_t rect_stat,
    void (*action)(struct paint_s *));
void free_buttons_from_menu(paint_t *paint, int menu_id);
void free_global_buttons(paint_t *paint);
// Buttons (Actions)
void save_image(paint_t *paint);
void exit_paint(paint_t *paint);
void no_action(paint_t *paint);
void size_10(paint_t *paint);
void size_20(paint_t *paint);
void size_30(paint_t *paint);
void size_40(paint_t *paint);
void size_50(paint_t *paint);
void default_color(paint_t *paint);
void color_red(paint_t *paint);
void color_blue(paint_t *paint);
void color_yellow(paint_t *paint);
void color_green(paint_t *paint);
void color_purple(paint_t *paint);
void eraser_action(paint_t *paint);
void pen_action(paint_t *paint);

// Assets (Button Handler)
void init_global_buttons(void);
void init_global_menus(void);
void analyze_button(paint_t *paint, button_t *button);
void analyze_menu(paint_t *paint, drop_menu_t *button);

// Draw
void draw_buttons(paint_t *paint);
void draw_drop(drop_menu_t *menu, paint_t *paint);
void draw_drop_menus(paint_t *paint);

// Utils
sfVector2f center_element_to_window(paint_t *paint, sfVector2f size);
sfVector2f get_center_of_text(sfText *text);
sfVector2f get_center_of_menu(rect_t rect_stat);
sfVector2f get_window_scale(paint_t *paint);

#endif
