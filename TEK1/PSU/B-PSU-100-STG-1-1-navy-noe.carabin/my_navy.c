/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** my_navy.c
*/

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include "include/my.h"

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

static void init_struct(table_t *position)
{
    position->player_position = crate_table();
    position->enemy_pos = crate_table();
    position->is_game_finish = false;
}

static int core(table_t *table)
{
    display(table);
}

int main(int ac, char **av)
{
    table_t *table = malloc(sizeof(table_t));

    init_struct(table);
    if (ac == 1 || ac > 3 || file_content_checker(av[ac - 1]) == 84)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    if (ac == 2) {
        get_info(av[1], 32, table);
        player_one_connection(table);
    }
    if (ac == 3) {
        get_info(av[2], 32, table);
        player_two_connection(av[1], table);
    }
    return 0;
}
