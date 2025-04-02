/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** game_scene
*/

#include "../../../include/csfml.h"

void start_fight(gui_t *gui, int ennemi, int lvl)
{
    gui->selected = select_scene(gui, FIGHT);
    gui->player.energy = 0;
    gui->player.utimate_energy = 0;
    create_data(&gui->selected->data_list, create_ennemy(gui, ennemi, lvl));
}

void end_fight(gui_t *gui)
{
    ennemy_t *ennemy = gui->selected->data_list->element;

    gui->player.stats.health = gui->player.stats.save_health;
    free(ennemy->name);
    destroy_csfml_sprite(ennemy->sprite);
    free(ennemy->sprite);
    destroy_data_list(&gui->selected->data_list);
    gui->selected->data_list = NULL;
    gui->selected = select_scene(gui, GAME_SCENE);
}

void fight_constructor(scene_t *scene, gui_t *gui)
{
    create_pannel(&scene->pannels, BUTTON, &draw_button_fight_pannel,
        &destroy_button_pannel);
    create_button_fight_pannel(scene->pannels, gui);
}

int fight_update(gui_t *gui)
{
    ennemy_t *ennemy = gui->selected->data_list->element;

    if (ennemy->stats.health <= 0){
        gui->player.fight_result = WIN;
        gui->player.stats.experience += 200;
        if (gui->player.stats.experience > 600){
            gui->player.stats.experience -= 600;
            gui->player.stats.level++;
        }
        end_fight(gui);
        return 0;
    }
    if (gui->player.stats.health <= 0){
        gui->player.fight_result = LOSE;
        end_fight(gui);
        return 0;
    }
    draw_pannels(gui->selected->pannels, gui);
    sfRenderWindow_drawSprite(gui->window, ennemy->sprite->sprite, NULL);
    return 0;
}
