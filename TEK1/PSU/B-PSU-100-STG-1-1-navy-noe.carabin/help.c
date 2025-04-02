/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** help.c
*/

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include "include/my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRITPION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player,");
    my_putstr("pid of the first player.\n");
    my_putstr("\tnavy_position: file representating the position");
    my_putstr("of the ships.\n");
}
