/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** player
*/

#include "../../../../include/csfml.h"

void move_world(gui_t *gui, float pos_x, float pos_y)
{
    if (is_collision_map(&gui->player, pos_x, pos_y))
        return;
    for (pannel_t *tmp = gui->selected->pannels; tmp != NULL; tmp = tmp->next){
        if (tmp->id == BUTTON || tmp->id == PLAYER)
            continue;
        if (tmp->id == EVENT){
            move_event_pannel(tmp->element, pos_x, pos_y);
            continue;
        }
        if (tmp->id == ENTITY){
            move_entity_pannel(tmp->element, pos_x, pos_y);
            continue;
        }
        move_map_pannel(tmp->element, pos_x, pos_y);
    }
}

static void player_translation_time(gui_t *gui, sfVector2f *dir, float ac_time)
{
    if (ac_time < 0.05)
        return;
    move_world(gui, dir->x, dir->y);
    sfClock_restart(gui->clock);
}

static void player_translation(gui_t *gui, float ac_time)
{
    sfVector2f dir = {0, 0};

    if (*gui->controls.last_key == gui->controls.mvt_up){
        anim_player(gui, 1, ac_time);
        dir.y = 41.6f;
    }
    if (*gui->controls.last_key == gui->controls.mvt_left){
        anim_player(gui, 2, ac_time);
        dir.x = 41.6f;
    }
    if (*gui->controls.last_key == gui->controls.mvt_right){
        anim_player(gui, 3, ac_time);
        dir.x = -41.6f;
    }
    if (*gui->controls.last_key == gui->controls.mvt_down){
        anim_player(gui, 4, ac_time);
        dir.y = -41.6f;
    }
    player_translation_time(gui, &dir, ac_time);
}

void player_move_event(gui_t *gui, event_entity_t *event)
{
    float ac_time;

    if (gui->controls.last_key == NULL)
        return;
    if (gui->is_echap == true)
        return;
    if (*gui->controls.last_key == gui->controls.interact)
        story_tell(gui, event);
    if (gui->player.entity->state != 0)
        return;
    ac_time = sfTime_asSeconds(sfClock_getElapsedTime(gui->clock));
    if (ac_time < 0.025)
        return;
    player_translation(gui, ac_time);
}
