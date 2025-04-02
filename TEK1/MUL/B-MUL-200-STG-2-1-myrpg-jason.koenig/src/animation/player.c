/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** player
*/

#include "../../include/csfml.h"

static void anim_player_up(gui_t *gui, sfIntRect *rect, float ac_time)
{
    if (ac_time > 0.05){
        rect->left = 48;
        rect->top = 0;
        return;
    }
    if (ac_time > 0.035){
        rect->left = 429;
        return;
    }
    if (ac_time > 0.025){
        rect->left = 477;
        return;
    }
}

static void anim_player_left(gui_t *gui, sfIntRect *rect, float ac_time)
{
    if (ac_time > 0.05){
        rect->left = 96;
        rect->top = 0;
        return;
    }
    if (ac_time > 0.035){
        rect->left = 717;
        return;
    }
    if (ac_time > 0.025){
        rect->left = 765;
        return;
    }
}

static void anim_player_right(gui_t *gui, sfIntRect *rect, float ac_time)
{
    if (ac_time > 0.05){
        rect->top = 0;
        return;
    }
    if (ac_time > 0.035){
        rect->left = 144;
        return;
    }
    if (ac_time > 0.025){
        rect->left = 189;
        return;
    }
}

static void anim_player_down(gui_t *gui, sfIntRect *rect, float ac_time)
{
    if (ac_time > 0.05){
        rect->left = 144;
        rect->top = 0;
        return;
    }
    if (ac_time > 0.035){
        rect->left = 1005;
        return;
    }
    if (ac_time > 0.025){
        rect->left = 1053;
        return;
    }
}

void anim_player(gui_t *gui, int state, float ac_time)
{
    sfIntRect rect;

    rect.top = 192;
    rect.left = 0;
    rect.height = 96;
    rect.width = 48;
    if (state == 1)
        anim_player_up(gui, &rect, ac_time);
    if (state == 2)
        anim_player_left(gui, &rect, ac_time);
    if (state == 3)
        anim_player_right(gui, &rect, ac_time);
    if (state == 4)
        anim_player_down(gui, &rect, ac_time);
    sfSprite_setTextureRect(gui->player.sprite->sprite, rect);
}
