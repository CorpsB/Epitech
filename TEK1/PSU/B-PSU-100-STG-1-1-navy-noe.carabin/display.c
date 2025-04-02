/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** display.c
*/

#include "include/my.h"

static void display_table_next(char **table, int i)
{
    for (int j = 0; j < 8; j++) {
        write(1, &table[i][j], 1);
            if (j + 1 != 8) {
                write(1, " ", 1);
            }
    }
}

static void display_table(char **table)
{
    char index = 0;

    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; i <= 7; i++) {
        index = i + 49;
        write(1, &index, 1);
        write(1, "|", 1);
        display_table_next(table, i);
        write(1, "\n", 1);
    }
}

void display(table_t *table)
{
    write(1, "\nmy navy:\n", 10);
    display_table(table->player_position);
    write(1, "\nenemy navy :\n", 14);
    display_table(table->enemy_pos);
    return;
}
