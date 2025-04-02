/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** add_button
*/

#include "../includes/my.h"
#include "../includes/paint.h"

static sfText *init_button_text(paint_t *paint, rect_t rect_stat)
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

void add_button_to_menu(paint_t *paint, rect_t rect_stat,
    int menu_id, void (*action)(paint_t *))
{
    button_t *button;
    drop_menu_t *tmp = paint->drop_menus;

    button = malloc(sizeof(button_t));
    while (paint->drop_menus != NULL){
        if (paint->drop_menus->id == menu_id){
            button->rect = sfRectangleShape_create();
            sfRectangleShape_setPosition(button->rect, rect_stat.position);
            sfRectangleShape_setSize(button->rect, rect_stat.size);
            sfRectangleShape_setFillColor(button->rect, GRAY_240);
            button->text = init_button_text(paint, rect_stat);
            button->next = paint->drop_menus->buttons;
            button->action = action;
            paint->drop_menus->buttons = button;
            break;
        }
        paint->drop_menus = paint->drop_menus->next;
    }
    paint->drop_menus = tmp;
}

void add_button(paint_t *paint, rect_t rect_stat, void (*action)(paint_t *))
{
    button_t *button;

    button = malloc(sizeof(button_t));
    button->state = 0;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, rect_stat.position);
    sfRectangleShape_setSize(button->rect, rect_stat.size);
    sfRectangleShape_setFillColor(button->rect, GRAY_240);
    button->text = init_button_text(paint, rect_stat);
    button->action = action;
    button->next = paint->buttons;
    paint->buttons = button;
}

static void free_buttons(button_t **buttons)
{
    button_t *target;

    while (*buttons != NULL){
        target = *buttons;
        sfRectangleShape_destroy((*buttons)->rect);
        sfText_destroy((*buttons)->text);
        *buttons = (*buttons)->next;
        free(target);
    }
}

void free_buttons_from_menu(paint_t *paint, int menu_id)
{
    button_t *target;
    drop_menu_t *tmp = paint->drop_menus;

    while (paint->drop_menus != NULL){
        if (paint->drop_menus->id == menu_id)
            free_buttons(&(paint->drop_menus->buttons));
        paint->drop_menus = paint->drop_menus->next;
    }
    paint->drop_menus = tmp;
}

void free_global_buttons(paint_t *paint)
{
    button_t *target;

    while (paint->buttons != NULL){
        target = paint->buttons;
        sfRectangleShape_destroy(paint->buttons->rect);
        sfText_destroy(paint->buttons->text);
        paint->buttons = paint->buttons->next;
        free(target);
    }
}
