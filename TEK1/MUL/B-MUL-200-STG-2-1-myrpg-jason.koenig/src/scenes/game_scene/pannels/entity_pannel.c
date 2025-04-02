/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** entity_pannel
*/

#include "../../../../include/csfml.h"

static void create_npc_entity(pannel_t *pannels, gui_t *gui,
    sfVector2i pos, char *img)
{
    sfIntRect rect;
    csfml_sprite_t *npc;

    rect.top = 0;
    rect.left = 144;
    rect.width = 48;
    rect.height = 96;
    npc = create_csfml_sprite(img,
    &(sfVector2f){gui->graphics.win_size.x / 2 + pos.x,
    gui->graphics.win_size.y / 2 + pos.y}, &rect);
    sfSprite_setScale(npc->sprite, (sfVector2f){0.85f, 0.85f});
    create_data(&pannels->element, npc);
}

static void create_player_entity(pannel_t *pannels, gui_t *gui)
{
    sfIntRect rect;
    csfml_sprite_t *player;

    rect.top = 0;
    rect.left = 144;
    rect.width = 48;
    rect.height = 96;
    player = create_csfml_sprite("assets/characters/main.png",
    &(sfVector2f){gui->graphics.win_size.x / 2, gui->graphics.win_size.y / 2},
    &rect);
    sfSprite_setScale(player->sprite, (sfVector2f){0.85f, 0.85f});
    gui->player.sprite = player;
    create_data(&pannels->element, player);
}

void create_entity_pannel(pannel_t *pannels, gui_t *gui)
{
    create_player_entity(pannels, gui);
    create_npc_entity(pannels, gui, (sfVector2i){10 * 41.6, 3 * 41.6},
        "assets/characters/npc_1.png");
    create_npc_entity(pannels, gui, (sfVector2i){18 * 41.6, 3 * 41.6},
        "assets/characters/npc_2.png");
    create_npc_entity(pannels, gui, (sfVector2i){57 * 41.6, 23 * 41.6},
        "assets/characters/npc_3.png");
    create_npc_entity(pannels, gui, (sfVector2i){67 * 41.6, -30 * 41.6},
        "assets/characters/npc_4.png");
    create_npc_entity(pannels, gui, (sfVector2i){20 * 41.6, -33 * 41.6},
        "assets/characters/npc_5.png");
}

void move_entity_pannel(element_t *elt, float pos_x, float pos_y)
{
    csfml_sprite_t *target;

    for (; elt->next != NULL; elt = elt->next){
        target = elt->element;
        target->pos.x += pos_x;
        target->pos.y += pos_y;
        sfSprite_setPosition(target->sprite, target->pos);
    }
}
