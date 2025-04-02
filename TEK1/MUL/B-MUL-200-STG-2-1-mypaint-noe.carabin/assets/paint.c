/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** destroy_paint
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static void init_paint_next(paint_t *paint, int is_from_file, char *pathname)
{
    struct stat filestat;
    sfVector2f image_size;

    paint->font = sfFont_createFromFile("fonts/default.ttf");
    paint->tool = 0;
    paint->pen_size = 5;
    paint->selected_color = BLACK;
    if (stat(pathname, &filestat) != -1){
        paint->image = sfImage_createFromFile(pathname);
    } else {
        paint->image = sfImage_createFromColor(1200, 675, WHITE);
    }
    image_size.x = (float)sfImage_getSize(paint->image).x;
    image_size.y = (float)sfImage_getSize(paint->image).y;
    paint->image_sprite = sfSprite_create();
    sfSprite_setPosition(paint->image_sprite, center_element_to_window(paint,
        image_size));
    paint->image_texture = sfTexture_createFromImage(paint->image, NULL);
    sfSprite_setTexture(paint->image_sprite, paint->image_texture, sfTrue);
}

void init_paint(paint_t *paint, int is_from_file, char *pahtname)
{
    paint->videoMode = (sfVideoMode){1600, 900, 32};
    paint->window = sfRenderWindow_create(paint->videoMode,
        "My Paint", sfResize | sfClose, NULL);
    paint->music = sfMusic_createFromFile("./sounds/music.ogg");
    paint->buttons = NULL;
    paint->drop_menus = NULL;
    init_paint_next(paint, is_from_file, pahtname);
    init_drop_menus(paint);
    init_buttons(paint);
    music_manager(paint);
}

void destroy_paint(paint_t *paint)
{
    sfRenderWindow_destroy(paint->window);
    sfMusic_destroy(paint->music);
    sfSprite_destroy(paint->image_sprite);
    sfTexture_destroy(paint->image_texture);
    sfImage_destroy(paint->image);
    sfFont_destroy(paint->font);
    free_drop_menus(paint);
    free_global_buttons(paint);
}

void draw_paint(paint_t *paint)
{
    sfRenderWindow_clear(paint->window, GRAY_220);
    sfRenderWindow_drawSprite(paint->window, paint->image_sprite, NULL);
    draw_drop_menus(paint);
    draw_buttons(paint);
    sfRenderWindow_display(paint->window);
}
