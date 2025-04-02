/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** gui
*/

#include "../include/csfml.h"

void init_binding(gui_t *gui)
{
    gui->controls.mvt_up = sfKeyUp;
    gui->controls.mvt_left = sfKeyLeft;
    gui->controls.mvt_right = sfKeyRight;
    gui->controls.mvt_down = sfKeyDown;
    gui->controls.act_1 = sfKeyA;
    gui->controls.act_2 = sfKeyB;
    gui->controls.interact = sfKeySpace;
    gui->controls.last_key = NULL;
}

static char **init_collision_map(void)
{
    char **tab = malloc(sizeof(char *) * 113);
    FILE *stream = fopen("assets/maps/main_shelter_col.txt", "r");
    char *buff = NULL;
    size_t size = 0;

    for (int i = 0; i < 112; ++i){
        getline(&buff, &size, stream);
        buff[my_strlen(buff) - 1] = '\0';
        tab[i] = my_strdup(buff);
        free(buff);
        buff = NULL;
        size = 0;
    }
    fclose(stream);
    tab[112] = NULL;
    return tab;
}

static void init_player(gui_t *gui)
{
    init_inventory(gui);
    gui->player.story_level = 0;
    gui->player.stats.level = 1;
    gui->player.stats.health = 42;
    gui->player.stats.save_health = 42;
    gui->player.stats.attack = 4;
    gui->player.stats.defense = 4;
    gui->player.stats.luck = 2;
    gui->player.stats.experience = 0;
    gui->player.name = my_strdup("M. Nolan");
    gui->player.pos_map.x = 21;
    gui->player.pos_map.y = 51;
    gui->player.collision_map = init_collision_map();
    gui->player.fight_result = LOSE;
}

void init_scenes(gui_t *gui)
{
    create_scene(gui, CONTROLS, &controls_update, "assets/back/settings.jpg");
        controls_constructor(gui->scenes, gui);
    create_scene(gui, SETTINGS, &settings_update, "assets/back/settings.jpg");
        settings_constructor(gui->scenes, gui);
    create_scene(gui, MAIN_MENU, &main_menu_update,
    "assets/back/main_menu.jpg");
        main_menu_constructor(gui->scenes, gui);
    create_scene(gui, GAME_SCENE, &game_scene_update, NULL);
        game_scene_constructor(gui->scenes, gui);
    create_scene(gui, FIGHT, &fight_update, "assets/back/battle_fight.jpg");
        fight_constructor(gui->scenes, gui);
    create_scene(gui, INVENTORY, &inventory_update, NULL);
        inventory_constructor(gui->scenes, gui);
}

static void init_jukebox(gui_t *gui)
{
    gui->jukebox.fallout = sfMusic_createFromFile("assets/sounds/fallout.ogg");
    gui->jukebox.fight = sfMusic_createFromFile("assets/sounds/fight.ogg");
    gui->jukebox.menu = sfMusic_createFromFile("assets/sounds/banger.ogg");
    sfMusic_setLoop(gui->jukebox.fallout, sfTrue);
    sfMusic_setLoop(gui->jukebox.fight, sfTrue);
    sfMusic_setLoop(gui->jukebox.menu, sfTrue);
}

void init_gui(gui_t *gui, sfRenderWindow *win)
{
    gui->graphics.idle = sfColor_fromRGB(192, 192, 192);
    gui->graphics.hover = sfColor_fromRGB(128, 128, 128);
    gui->graphics.clicked = sfColor_fromRGB(64, 64, 64);
    gui->graphics.win_size = sfRenderWindow_getSize(win);
    gui->scenes = NULL;
    gui->window = win;
    gui->graphics.font =
    sfFont_createFromFile("assets/fonts/TitilliumWeb.ttf");
    gui->player.dialog = create_dialog_box(gui);
    gui->clock = sfClock_create();
    init_binding(gui);
    init_scenes(gui);
    init_jukebox(gui);
    init_player(gui);
    gui->selected = select_scene(gui, MAIN_MENU);
    gui->player.entity->state = 1;
    story_tell(gui, gui->player.entity);
    gui->is_echap = false;
}

int update_gui(gui_t *gui)
{
    int err_code;

    if (gui->selected->back != NULL)
        sfRenderWindow_drawSprite(gui->window, gui->selected->back->sprite,
        NULL);
    if (gui->player.fight_result == WIN)
        history_3(gui);
    err_code = gui->selected->update_func(gui);
    gui->controls.last_key = NULL;
    return err_code;
}

static void destroy_jukebox(gui_t *gui)
{
    sfMusic_destroy(gui->jukebox.fallout);
    sfMusic_destroy(gui->jukebox.fight);
    sfMusic_destroy(gui->jukebox.menu);
}

void destroy_gui(gui_t *gui, sfBool clean_all)
{
    if (clean_all)
        delete_window(gui->window);
    delete_inv(&(gui->inv));
    sfClock_destroy(gui->clock);
    sfFont_destroy(gui->graphics.font);
    destroy_dialog(gui->player.dialog);
    destroy_scenes(&gui->scenes);
    destroy_jukebox(gui);
    free(gui->player.name);
    a_free(gui->player.collision_map);
}
