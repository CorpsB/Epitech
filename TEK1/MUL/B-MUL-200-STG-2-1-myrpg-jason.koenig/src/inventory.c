/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** inventory.c
*/

#include "../include/csfml.h"

static sfRectangleShape *create_hitbox(gui_t *gui, sfVector2f pos)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfFloatRect center;

    sfRectangleShape_setSize(hitbox, (sfVector2f){50, 50});
    center = sfRectangleShape_getLocalBounds(hitbox);
    sfRectangleShape_setOrigin(hitbox, (sfVector2f){center.width / 2,
    center.top / 2});
    sfRectangleShape_setFillColor(hitbox, gui->graphics.idle);
    sfRectangleShape_setPosition(hitbox, pos);
    return hitbox;
}

static sfSprite *create_texture(gui_t *gui, sfVector2f pos, char *file,
    sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfFloatRect center;
    sfVector2f scale;
    sfVector2u size = sfTexture_getSize(texture);

    sfSprite_setTexture(sprite, texture, sfFalse);
    scale = (sfVector2f){45.0 / size.x, 45.0 / size.y};
    sfSprite_setScale(sprite, scale);
    center = sfSprite_getLocalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){center.width / 2, center.top / 2});
    sfSprite_setPosition(sprite, (sfVector2f){pos.x + 2.5, pos.y + 2.5});
    return sprite;
}

void add(inventory_t **inv, sfVector2f pos, gui_t *gui, char *file)
{
    inventory_t *tmp = malloc(sizeof(inventory_t));

    tmp->texture = sfTexture_createFromFile(file, NULL);
    tmp->hitbox = create_hitbox(gui, pos);
    tmp->item = create_texture(gui, pos, file, tmp->texture);
    tmp->player_have = false;
    tmp->selected = false;
    tmp->next = *inv;
    *inv = tmp;
}

void init_inventory(gui_t *gui)
{
    inventory_t *inv = NULL;
    int x = gui->graphics.win_size.x / 6;
    int y = gui->graphics.win_size.y / 4;

    add(&inv, (sfVector2f){x * 1, y * 1}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 2, y * 1}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 3, y * 1}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 4, y * 1}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 5, y * 1}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 1, y * 2}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 2, y * 2}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 3, y * 2}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 4, y * 2}, gui, "./assets/items/items.png");
    add(&inv, (sfVector2f){x * 5, y * 2}, gui, "./assets/items/items.png");
    gui->inv = inv;
}

void delete_inv(inventory_t **inv)
{
    inventory_t *target;
    inventory_t *tmp = *inv;

    while (tmp != NULL){
        target = tmp;
        sfRectangleShape_destroy(tmp->hitbox);
        sfTexture_destroy(tmp->texture);
        sfSprite_destroy(tmp->item);
        tmp = tmp->next;
        free(target);
    }
}
