/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** is_win.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdbool.h>

int count_x_in_line(const char *line)
{
    int count_x = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == 'x') {
            count_x++;
        }
    }
    return count_x;
}

bool is_win(char **tabl)
{
    int count_x = 0;
    bool iswin = false;

    for (int i = 0; i < 8; i++) {
        count_x += count_x_in_line(tabl[i]);
    }
    if (count_x == 14)
        iswin = true;
    return iswin;
}

int finish_game(table_t *table, int nbr)
{
    if (nbr == 65) {
        my_printf("Enemy won\n");
    } else {
        my_printf("I won\n");
    }
    free(table->enemy_pos);
    free(table->player_position);
    return 0;
}
