/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** create_scene
*/

#include "../../include/csfml.h"

static scene_t *select_scene_music(scene_t *tmp, gui_t *gui)
{
    if (tmp->id == GAME_SCENE){
        sfMusic_stop(gui->jukebox.fight);
        sfMusic_stop(gui->jukebox.menu);
        sfMusic_play(gui->jukebox.fallout);
        return tmp;
    }
    if (tmp->id == FIGHT){
        sfMusic_play(gui->jukebox.fight);
        sfMusic_stop(gui->jukebox.menu);
        sfMusic_stop(gui->jukebox.fallout);
        return tmp;
    }
    sfMusic_stop(gui->jukebox.fight);
    if (sfMusic_getStatus(gui->jukebox.menu) == sfStopped)
        sfMusic_play(gui->jukebox.menu);
    sfMusic_stop(gui->jukebox.fallout);
    return tmp;
}

scene_t *select_scene(gui_t *gui, int id)
{
    for (scene_t *tmp = gui->scenes; tmp != NULL; tmp = tmp->next)
        if (tmp->id == id)
            return select_scene_music(tmp, gui);
}

void create_scene(gui_t *gui, int id,
    int (*update_func)(gui_t *gui), char *back)
{
    scene_t *s_list = malloc(sizeof(struct scene_s));
    float r_width = gui->graphics.win_size.x / 1366;
    float r_height = gui->graphics.win_size.y / 768;
    float r_fil = (r_width < r_height) ? r_width * 1.1 : r_height * 1.1;

    s_list->update_func = update_func;
    s_list->id = id;
    s_list->data_list = NULL;
    s_list->pannels = NULL;
    if (back == NULL)
        s_list->back = NULL;
    else {
        s_list->back = create_csfml_sprite(back,
        &(sfVector2f){gui->graphics.win_size.x / 2,
        gui->graphics.win_size.y / 2}, NULL);
        sfSprite_setScale(s_list->back->sprite, (sfVector2f){r_fil, r_fil});
    }
    s_list->next = gui->scenes;
    gui->scenes = s_list;
}

void destroy_scenes(scene_t **list)
{
    scene_t *target;
    scene_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        if (tmp->back != NULL){
            destroy_csfml_sprite(tmp->back);
            free(tmp->back);
        }
        destroy_data_list(&tmp->data_list);
        destroy_pannels(&tmp->pannels);
        tmp = tmp->next;
        free(target);
    }
}
