/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** player2.c
*/

#include "include/my.h"

//Penser à free quand fini ...
static int player_two(table_t *table)
{
    int nbr = 0;

    while (!is_win(table->enemy_pos)) {
        display(table);
        my_printf("\nwaiting for enemy's attack...\n");
        istouch(table);
        nbr = attack(table);
        if (nbr == 65)
            break;
        attack_result(table, nbr);
    }
    finish_game(table, nbr);
}

static void sig2_f2(int nbr)
{
    return;
}

int player_two_connection(char *id, table_t *table)
{
    int error_case = 0;

    my_printf("my_pid: %i\n", getpid());
    signal(10, sig2_f2);
    table->pid = get_nbr(id);
    error_case = kill(table->pid, 12);
    signal(SIGUSR1, sig1_f);
    signal(SIGUSR2, sig2_f);
    if (error_case == 0 && receive_pos() == 1);
        write(1, "\nsuccessfully connected\n", 24);
        return player_two(table);
    return 84;
}
