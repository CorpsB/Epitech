/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** player1.c
*/

#include "include/my.h"
#include <stdio.h>

void signalhandler(int signo, siginfo_t *info, void *context)
{
    send_pid(info->si_pid);
}

void signal2(int nbr)
{
    return;
}

// int stock(int nbr, enum what w) {
//     static int save = -1;
//     if (w == SET)
//         save = nbr;
//     return save;
// }
static void player_one(table_t *table)
{
    int nbr = 0;

    while (!is_win(table->enemy_pos)) {
        display(table);
        nbr = attack(table);
        if (nbr == 65)
            break;
        attack_result(table, nbr);
        my_printf("\nwaiting for enemy's attack...\n");
        istouch(table);
    }
    finish_game(table, nbr);
}

void player_one_connection(table_t *table)
{
    pid_t pid1 = getpid();
    struct sigaction sa;

    my_printf("my_pid: %i\n", pid1);
    sa.sa_sigaction = signalhandler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    my_printf("\nwaiting for enemy ...\n");
    pause();
    table->pid = get_pid(0);
    my_putstr("\nenemy connected\n");
    signal(SIGUSR1, sig1_f);
    signal(SIGUSR2, sig2_f);
    send_pos(1, table->pid);
    player_one(table);
}
