/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** connection.c
*/

#include "include/my.h"

void player1(int signum)
{
    pid_t pid1 = getpid();
    sig_atomic_t signal_received1 = 0;

    if (signum == SIGUSR2) {
        signal_received1 = 1;
        signal(SIGUSR2, signal_received1);
    }
    my_printf("my_pid: %i\n", pid1);
    while (!signal_received1) {
        my_printf("waiting for enemy ...\n");
        sleep(1);
    }
    my_putstr("enemy connected\n");
}

void player2(pid_t pid_player1)
{
    pid_t pid2;

    pid2 = getpid();
    my_printf("my_pid: %i\n", pid2);
    kill(pid_player1, SIGUSR2);
    while (1) {
        pause();
    }
}
