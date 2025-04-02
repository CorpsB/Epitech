/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-noe.carabin
** File description:
** main.c
*/

#include "my.h"
#include <unistd.h>

void help_fonction(void)
{
    write(1, "USAGE :\n", 8);
    write(1, "./my_raadar FILEPATH\n", 21);
    write(1, "FILEPATH : A filepath or file that content info for the", 55);
    write(1, " simulation.\n EXAMPLE :\n", 24);
    write(1, "A X_START Y_START X_END Y_END SPEED DELAY", 41);
    write(1, "T COO_X COO_Y\n\nEvery coordonate must be inside the windo", 56);
    write(1, "w (1920 * 1080)\n", 14);
    return;
}

void free_planes(plane_t **list)
{
    plane_t *target;
    plane_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        sfRectangleShape_destroy(tmp->hit_box);
        sfSprite_destroy(tmp->plane);
        tmp = tmp->next;
        free(target);
    }
}

void free_towers(tower_t **list)
{
    tower_t *target;
    tower_t *tmp = *list;

    while (tmp != NULL){
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}

int get_file_and_error(int ac, char **av, plane_t **plane, tower_t **tower)
{
    int error_detector = 0;

    if (ac == 1){
        write(1, "Pas de fichier en argument ...\n", 31);
        return 84;
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_fonction();
    error_detector = file_extractor(av[1], plane, tower);
    return error_detector;
}

static void init_windows(game_t *game)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    game->vm = video_mode;
    game->win = sfRenderWindow_create(game->vm, "My_radar",
    sfResize | sfClose, NULL);
    game->clock = sfClock_create();
}

int main(int ac, char **av)
{
    plane_t *plane_list = NULL;
    tower_t *tower_list = NULL;
    game_t *game = malloc(sizeof(game_t));

    if (get_file_and_error(ac, av, &plane_list, &tower_list) == 84)
        return 84;
    init_windows(game);
    core(game, plane_list, tower_list);
    free_planes(&plane_list);
    free_towers(&tower_list);
    sfRenderWindow_destroy(game->win);
    sfClock_destroy(game->clock);
    free(game);
}
