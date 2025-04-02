/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** main.c
*/

#include "my.h"

static void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap\tfile representing the warehouse map,");
    my_putstr("containing '#' for walls,\n\t\t'P' for the player, 'X'");
    my_putstr("for boxes and 'O' for storage loactions.\n");
}

int main(int ac, char **av)
{
    linked_t *infos_position = malloc(sizeof(linked_t));
    char *pre_map;
    char **map;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    while (1) {
        infos_position = NULL;
        if (ac != 2)
            return 84;
        pre_map = file_checker(av[1]);
        map = get_informtion_array(pre_map, &infos_position);
        if (core(map, infos_position) == false)
            break;
    }
    free_everything(infos_position, pre_map, map);
    return 0;
}
