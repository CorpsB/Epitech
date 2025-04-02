/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** button.c
*/

#include "../../../include/csfml.h"

static sfText *create_text(char *str, sfVector2f *pos, gui_t *gui)
{
    sfText *text = sfText_create();

    sfText_setFont(text, gui->graphics.font);
    sfText_setString(text, str);
    sfText_setOrigin(text,
        (sfVector2f){sfText_getLocalBounds(text).width / 2,
        sfText_getLocalBounds(text).height / 2});
    sfText_setPosition(text, *pos);
    sfText_setColor(text, sfBlack);
    return text;
}

static sfRectangleShape *create_rectangle(sfVector2f *pos, sfVector2f *size,
    sfColor *color)
{
    sfRectangleShape *btn = sfRectangleShape_create();

    sfRectangleShape_setSize(btn, *size);
    sfRectangleShape_setOrigin(btn,
        (sfVector2f){sfRectangleShape_getLocalBounds(btn).width / 2,
        sfRectangleShape_getLocalBounds(btn).height / 2});
    sfRectangleShape_setOutlineColor(btn, sfBlack);
    sfRectangleShape_setOutlineThickness(btn, 1);
    sfRectangleShape_setFillColor(btn, *color);
    sfRectangleShape_setPosition(btn, *pos);
    return btn;
}

button_t *create_button(char *text, sfVector2f *pos,
    void (*bt_func)(struct button_s *button), button_graphics_shema_t *shema)
{
    button_t *button = malloc(sizeof(button_t));

    button->box = create_rectangle(pos, &shema->size, &sfWhite);
    button->text = create_text(text, pos, shema->gui);
    button->bt_func = bt_func;
    button->gui = shema->gui;
    button->pos.x = pos->x;
    button->pos.y = pos->y;
    button->button_state = IDLE;
    return button;
}

void draw_button(button_t *button)
{
    button_state(button);
    sfRenderWindow_drawRectangleShape(button->gui->window, button->box, NULL);
    sfRenderWindow_drawText(button->gui->window, button->text, NULL);
}

void destroy_button(button_t *button)
{
    sfRectangleShape_destroy(button->box);
    sfText_destroy(button->text);
}

void draw_button_pannel(element_t *elt, gui_t *gui)
{
    button_t *target;

    for (element_t *tmp = elt; tmp != NULL; tmp = tmp->next){
        target = tmp->element;
        draw_button(target);
    }
}

void destroy_button_pannel(element_t *elt)
{
    button_t *target;

    for (; elt != NULL; elt = elt->next){
        target = elt->element;
        destroy_button(target);
    }
}
