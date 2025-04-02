/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-noe.carabin
** File description:
** main2.c
*/

#include "my.h"

static void animated_sprite(window_t *game, int i)
{
    int nbr = 110;
    int max = 330;

    game->sprite[i]->rect.left += nbr;
    if (game->sprite[i]->rect.left >= 330) {
        game->sprite[i]->rect.left = 0;
    }
    if (sfSprite_getPosition(game->sprite[i]->sprite).x > 1920.00) {
        game->sprite[i]->pos = (sfVector2f){-100.00, rand() % 1000 + 10};
        sfSprite_setPosition(game->sprite[i]->sprite,
        (sfVector2f)game->sprite[i]->pos);
    }
    sfSprite_setTextureRect(game->sprite[i]->sprite, game->sprite[i]->rect);
    sfSprite_move(game->sprite[i]->sprite, game->mouv);
}

static void animated_every_sprite(window_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);

    if (sfTime_asSeconds(time) > 0.1) {
        for (int i = 1; i < 6; i++) {
            animated_sprite(game, i);
        }
        sfClock_restart(game->clock);
    }
}

static void analyse_events(window_t *game)
{
    while (sfRenderWindow_pollEvent(game->win, &(game->event))) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win);
        }
        if (game->event.type == sfEvtMouseButtonPressed) {
            analyse_clic(game);
        }
    }
}

static sfSprite *generate_sprite(sfVector2f *pos, sfVector2f *scale,
    sfTexture *text)
{
    sfSprite *tmp = sfSprite_create();

    sfSprite_setTexture(tmp, text, sfTrue);
    sfSprite_setPosition(tmp, *pos);
    sfSprite_setScale(tmp, *scale);
    return (tmp);
}

static void create_object(window_t *game, sfVector2f *pos,
    sfVector2f *scale, char *filepath)
{
    int index;
    sfTexture *text = sfTexture_createFromFile(filepath, NULL);

    game->entities++;
    index = game->entities - 1;
    game->sprite[index] = malloc(sizeof(sprite_t));
    if (index > 0) {
        game->sprite[index]->rect.height = 110;
        game->sprite[index]->rect.width = 110;
        game->sprite[index]->rect.top = 0;
        game->sprite[index]->rect.left = 0;
    }
    (game->sprite[index])->sprite = generate_sprite(pos, scale, text);
}

static void draw_sprite(window_t *game)
{
    for (int i = 0; i < game->entities; i++) {
        sfRenderWindow_drawSprite(game->win, game->sprite[i]->sprite, NULL);
        if (i > 0) {
            sfSprite_setTextureRect(game->sprite[i]->sprite,
            game->sprite[i]->rect);
        }
    }
}

static void generator(window_t *game)
{
    sfVector2f pos_b = {0, 0};
    sfVector2f pos_d = {0, 0};
    sfVector2f size_b = {2.1, 1.7};
    sfVector2f size_d = {1, 1};

    create_object(game, &pos_b, &size_b, "sprite/background.jpg");
    create_object(game, &pos_d, &size_d, "sprite/Normal-bird.png");
    create_object(game, &pos_d, &size_d, "sprite/Normal-bird.png");
    create_object(game, &pos_d, &size_d, "sprite/Normal-bird.png");
    create_object(game, &pos_d, &size_d, "sprite/Normal-bird.png");
    create_object(game, &pos_d, &size_d, "sprite/Normal-bird.png");
}

static void core(window_t *game, sfSprite *cursor)
{
    sfVector2f mousef;
    sfVector2f mouse_pos = {2.00, 2.00};

    sfMusic_setLoop(game->audio, sfTrue);
    sfMusic_play(game->audio);
    sfSprite_setOrigin(cursor, mouse_pos);
    generator(game);
    while (sfRenderWindow_isOpen(game->win)) {
        analyse_events(game);
        animated_every_sprite(game);
        sfRenderWindow_clear(game->win, sfBlack);
        draw_sprite(game);
        mousef.x = (float)sfMouse_getPositionRenderWindow(game->win).x;
        mousef.y = (float)sfMouse_getPositionRenderWindow(game->win).y;
        sfSprite_setPosition(cursor, mousef);
        sfRenderWindow_drawSprite(game->win, cursor, NULL);
        sfRenderWindow_display(game->win);
    }
}

static void init_win(void)
{
    window_t *game = malloc(sizeof(window_t));
    sfVideoMode video_mod = {1920, 1080, 32};
    sfTexture *cursor_t = sfTexture_createFromFile("sprite/mouse.png", NULL);
    sfSprite *cursor = sfSprite_create();
    sfVector2f size = {5.00, 5.00};

    game->sprite = malloc(sizeof(sprite_t *) * 7);
    game->sprite[6] = NULL;
    game->vm = video_mod;
    game->win = sfRenderWindow_create(game->vm, "My_hunter", sfClose , NULL);
    sfRenderWindow_setFramerateLimit(game->win, 30);
    game->entities = 0;
    game->clock = sfClock_create();
    game->speed = 10.00;
    game->mouv = (sfVector2f){game->speed, 0.00};
    game->audio = sfMusic_createFromFile("sprite/music.ogg");
    sfRenderWindow_setMouseCursorVisible(game->win, sfFalse);
    sfSprite_setTexture(cursor, cursor_t, sfTrue);
    sfSprite_setScale(cursor, size);
    core(game, cursor);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        init_win();
        return 0;
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "A lot of duck is in coming, to win, you need to kill ", 53);
        write(1, "it. You don't need any input to play the game. ", 47);
        write(1, "If you put an input, the program will return 84\n", 48);
        write(1, "Music name : Duck || By : Dee Yan-Key\n", 39);
        return 0;
    }
    return 84;
}
