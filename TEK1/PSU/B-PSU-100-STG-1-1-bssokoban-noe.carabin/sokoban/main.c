/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-bssokoban-noe.carabin
** File description:
** main.c
*/

#include "my.h"

void displayStrings(char **strings) {
    int i = 0;

    while (strings[i] != NULL) {
        printf("%s\n", strings[i]);
        ++i;
    }
}

int main(int ac, char **av)
{
    char **map;
    if (ac < 2 || ac > 2) {
        my_putstr("Invalid inputs");
        return (84);
    }
    map = get_array(av[1]);
    displayStrings(map);
}

