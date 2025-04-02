/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** event_pannel
*/

#include "../../../../include/csfml.h"

static void create_history(pannel_t *pan, gui_t *gui)
{
    create_data(&pan->element, create_event_entity(&history_1,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 38 + 19,
        gui->graphics.win_size.y / 2 - 41.6 * 28 + 19},
        &(sfVector2f){76, 36}));
    create_data(&pan->element, create_event_entity(&teleporter,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 19,
        gui->graphics.win_size.y / 2 - 41.6 * 32 + 19},
        &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&history_2,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2,
        gui->graphics.win_size.y / 2 + 19}, &(sfVector2f){36, 36}));
}

static void create_npc_event_pannel_3(pannel_t *pan, gui_t *gui, int pos)
{
    create_data(&pan->element, create_event_entity(&player_npc_5,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 20 + pos,
        gui->graphics.win_size.y / 2 - 1331.2 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_5,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 19 + pos,
        gui->graphics.win_size.y / 2 - 1372.8 + 19}, &(sfVector2f){36, 36}));
}

static void create_npc_event_pannel_2(pannel_t *pan, gui_t *gui, int pos)
{
    create_data(&pan->element, create_event_entity(&player_npc_3,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 56 + pos,
        gui->graphics.win_size.y / 2 + 956.8 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_3,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 57 + pos,
        gui->graphics.win_size.y / 2 + 998.4 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_4,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 66 + pos,
        gui->graphics.win_size.y / 2 - 1248 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_4,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 67 + pos,
        gui->graphics.win_size.y / 2 - 1289.6 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_5,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 20 + pos,
        gui->graphics.win_size.y / 2 - 1414.4 + 19}, &(sfVector2f){36, 36}));
    create_data(&pan->element, create_event_entity(&player_npc_5,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 21 + pos,
        gui->graphics.win_size.y / 2 - 1372.8 + 19}, &(sfVector2f){36, 36}));
    create_npc_event_pannel_3(pan, gui, pos);
}

static void create_npc_event_pannel(pannel_t *pannels, gui_t *gui, int pos)
{
    create_data(&pannels->element, create_event_entity(&player_npc_1,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 9 + pos,
        gui->graphics.win_size.y / 2 + 41.6 * 3 + 19}, &(sfVector2f){36, 36}));
    create_data(&pannels->element, create_event_entity(&player_npc_1,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 10 + pos,
        gui->graphics.win_size.y / 2 + 41.6 * 2 + 19}, &(sfVector2f){36, 36}));
    create_data(&pannels->element, create_event_entity(&player_npc_2,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 18 + pos,
        gui->graphics.win_size.y / 2 + 41.6 * 4 + 19}, &(sfVector2f){36, 36}));
    create_data(&pannels->element, create_event_entity(&player_npc_2,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 19 + pos,
        gui->graphics.win_size.y / 2 + 41.6 * 3 + 19}, &(sfVector2f){36, 36}));
    create_data(&pannels->element, create_event_entity(&player_npc_2,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 18 + pos,
        gui->graphics.win_size.y / 2 + 41.6 * 2 + 19}, &(sfVector2f){36, 36}));
    create_data(&pannels->element, create_event_entity(&player_npc_3,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 41.6 * 57 + pos,
        gui->graphics.win_size.y / 2 + 915.2 + 19}, &(sfVector2f){36, 36}));
    create_npc_event_pannel_2(pannels, gui, pos);
}

static void create_tp_event_pannel2(pannel_t *pannels, gui_t *gui,
    void (*evt_fc)(gui_t *, event_entity_t *), int pos)
{
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 2724.3,
        gui->graphics.win_size.y / 2 + 643 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 3972.3,
        gui->graphics.win_size.y / 2 + 2015.8 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 2724,
        gui->graphics.win_size.y / 2 - 979.4 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 1600.8,
        gui->graphics.win_size.y / 2 - 979.4 + pos}, &(sfVector2f){76, 36}));
}

static void create_tp_event_pannel(pannel_t *pannels, gui_t *gui,
    void (*evt_fc)(gui_t *, event_entity_t *), int pos)
{
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 228,
        gui->graphics.win_size.y / 2 - 22.6 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 269.6,
        gui->graphics.win_size.y / 2 + 393.4 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 976.8,
        gui->graphics.win_size.y / 2 - 22.6 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 1018.7,
        gui->graphics.win_size.y / 2 + 393.4 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 1601.1,
        gui->graphics.win_size.y / 2 + 643 + pos}, &(sfVector2f){76, 36}));
    create_data(&pannels->element, create_event_entity(evt_fc,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 2058.7,
        gui->graphics.win_size.y / 2 + 643 + pos}, &(sfVector2f){76, 36}));
    create_tp_event_pannel2(pannels, gui, evt_fc, pos);
}

// create_data(&pannels->element, create_event_entity(&player_tp_up,
//         gui, &(sfVector2f){gui->graphics.win_size.x / 2 + 208,
//         gui->graphics.win_size.y / 2 - 22.6}, &(sfVector2f){36, 36}));
void create_event_pannel(pannel_t *pannels, gui_t *gui)
{
    create_data(&pannels->element, create_event_entity(&player_move_event,
        gui, &(sfVector2f){gui->graphics.win_size.x / 2,
        gui->graphics.win_size.y / 2 + 19}, &(sfVector2f){36, 36}));
    gui->player.entity = pannels->element->element;
    create_tp_event_pannel(pannels, gui, &player_tp_up, 0);
    create_tp_event_pannel(pannels, gui, &player_tp_down, -124.8f);
    create_npc_event_pannel(pannels, gui, 0.0);
    create_history(pannels, gui);
}
