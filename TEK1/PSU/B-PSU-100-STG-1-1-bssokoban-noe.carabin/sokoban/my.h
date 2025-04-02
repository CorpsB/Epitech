/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-noe.carabin
** File description:
** my.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
//#include <curses.h>
//#include <unistd.h>

#ifndef MY_SOKOBAN
    #define MY_SOKOBAN

char **get_array(char *str);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

typedef struct file_t
{
    int size;
    char *content;
    char **tab;
} file_content;

#endif /*MY_SOKOBAN*/