/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-robotfactory-thibaut.louis
** File description:
** print_help.c
*/

#include "../include/my.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_name file in assembly language to be converted");
    my_putstr("into file_name.cor, an executable in\n");
    my_putstr("the Virtual Machine.\n");
}
