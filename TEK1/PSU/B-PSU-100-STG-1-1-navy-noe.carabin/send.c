/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** send.c
*/

#include "include/my.h"

void send_pos(int nrb, int pid)
{
    int i = 0;

    while (i < nrb / 10) {
        usleep(1000);
        kill(pid, SIGUSR1);
        i++;
    }
    usleep(2000);
    kill(pid, SIGUSR2);
    i = 0;
    while (i < nrb % 10) {
        usleep(1000);
        kill(pid, SIGUSR1);
        i++;
    }
    usleep(1000);
    kill(pid, SIGUSR2);
    return;
}
