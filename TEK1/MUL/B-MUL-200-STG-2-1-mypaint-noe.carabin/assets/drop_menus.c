/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** add_drop_menus
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static sfText *init_drop_menu_text(paint_t *paint, rect_t rect_stat)
{
    sfText *text;
    sfVector2f center_position;
    sfFloatRect text_rect;

    text = sfText_create();
    sfText_setString(text, rect_stat.text);
    sfText_setFont(text, paint->font);
    sfText_setCharacterSize(text, 15);
    sfText_setColor(text, BLACK);
    text_rect = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        text_rect.left + text_rect.width / 2.0f,
        text_rect.top + text_rect.height / 2.0f
    });
    center_position = get_center_of_menu(rect_stat);
    sfText_setPosition(text, center_position);
    return text;
}

void add_drop_menu(paint_t *paint, rect_t rect_stat, int id)
{
    drop_menu_t *drop_menu;

    drop_menu = malloc(sizeof(drop_menu_t));
    drop_menu->id = id;
    drop_menu->buttons = NULL;
    drop_menu->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(drop_menu->rect, rect_stat.position);
    sfRectangleShape_setSize(drop_menu->rect, rect_stat.size);
    sfRectangleShape_setFillColor(drop_menu->rect, GRAY_240);
    drop_menu->text = init_drop_menu_text(paint, rect_stat);
    drop_menu->state = 0;
    drop_menu->str = my_strdup(rect_stat.text);
    drop_menu->next = paint->drop_menus;
    paint->drop_menus = drop_menu;
}

void free_drop_menus(paint_t *paint)
{
    drop_menu_t *target;

    while (paint->drop_menus != NULL){
        target = paint->drop_menus;
        free(paint->drop_menus->str);
        sfRectangleShape_destroy(paint->drop_menus->rect);
        sfText_destroy(paint->drop_menus->text);
        free_buttons_from_menu(paint, paint->drop_menus->id);
        paint->drop_menus = paint->drop_menus->next;
        free(target);
    }
}
