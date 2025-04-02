/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** attack_result.c
*/

#include "include/my.h"

static int error_detector(char *str)
{
    int error = 0;

    if (str[0] > 'H' || str[0] < 'A')
        error++;
    if (str[1] > '8' || str[1] < '1')
        error++;
    if (error != 0) {
        return 84;
    } else {
        return 0;
    }
}

int attack(table_t *table)
{
    int co = 0;
    char *line = NULL;
    size_t len = 0;
    int error = 1;

    write(1, "\nattack: ", 9);
    while (1) {
        if (getline(&line, &len, stdin) != 3 || error_detector(line) == 84) {
            my_printf("\nwrong position\n");
            write(1, "\nattack: ", 9);
            continue;
        }
        break;
    }
    co += ((line[1] - '0') - 1) * 10;
    co += (line[0] - 'A');
    free(line);
    send_pos(co, table->pid);
    return co;
}

int attack_result(table_t *table, int nbr)
{
    int istouch = receive_pos();

    if (istouch == 67) {
        my_printf("\nresult: %c%c:hit\n", (nbr % 10 + 'A'), (nbr / 10 + '1'));
        table->enemy_pos[nbr % 10][nbr / 10] = 'x';
    } else {
        my_printf("\nresult: %c%c:missed\n",
        (nbr % 10 + 'A'), (nbr / 10 + '1'));
        table->enemy_pos[nbr / 10][nbr % 10] = 'o';
    }
}

int istouch(table_t *table)
{
    int nbr = receive_pos();

    if (table->player_position[nbr / 10][nbr % 10] < '9' &&
    table->player_position[nbr / 10][nbr % 10] > '0') {
        my_printf("\nresult: %c%c:hit\n", (nbr % 10 + 'A'), (nbr / 10 + '1'));
        table->player_position[nbr / 10][nbr % 10] = 'x';
        send_pos(67, table->pid);
    } else {
        my_printf("\nresult: %c%c:missed\n",
        (nbr % 10 + 'A'), (nbr / 10 + '1'));
        table->player_position[nbr / 10][nbr % 10] = 'o';
        send_pos(68, table->pid);
    }
    return nbr;
}
