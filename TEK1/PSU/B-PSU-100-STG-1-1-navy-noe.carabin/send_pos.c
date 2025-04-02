/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** send_pos.c
*/

#include "include/my.h"

sig_2 sig;

void sig1_f(int nbr)
{
    sig.sig1++;
}

void sig2_f(int nbr)
{
    sig.sig2++;
}

int receive_pos(void)
{
    int nbr = 0;

    sig.sig1 = 0;
    sig.sig2 = 0;
    while (sig.sig2 == 0);
    nbr = sig.sig1 * 10;
    sig.sig2 = 0;
    sig.sig1 = 0;
    while (sig.sig2 == 0);
    nbr += sig.sig1;
    return nbr;
}

static void give_coords(int *table_pos, int nbr)
{
    if (nbr % 8 == 0) {
        table_pos[0] = nbr / 8 - 1;
        table_pos[1] = 7;
    } else {
        table_pos[0] = nbr / 8;
        table_pos[1] = nbr % 8 - 1;
    }
    return;
}

int send_pid(int nbr)
{
    sig.pid = nbr;
}

int get_pid(int nbr)
{
    return sig.pid;
}
