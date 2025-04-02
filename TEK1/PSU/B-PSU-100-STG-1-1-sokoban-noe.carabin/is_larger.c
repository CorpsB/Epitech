/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-sokoban-noe.carabin
** File description:
** is_larger.c
*/

#include "my.h"

static void print_error(int hauteur, int largeur)
{
    for (int i = 0; i != hauteur / 2; i++)
        printw("\n");
    for (int i = 0; i != largeur / 2; i++)
        printw(" ");
    printw("Resize me");
    return;
}

// bool is_larger(char **map)
// {
//     int temp_largeur = 0;
//     int largeur = 0;
//     int hauteur = 0;
//     int ter_h;
//     int ter_l;

//     for (; map[hauteur] != NULL; hauteur++) {
//         for (; map[hauteur][temp_largeur] != '\0'; temp_largeur++)
//         if (temp_largeur > largeur)
//             largeur = temp_largeur;
//         temp_largeur = 0;
//     }
//     getmaxyx(stdscr, ter_h, ter_l);
//     if (ter_h < hauteur || ter_l < largeur) {
//         print_error(ter_h, ter_l);
//         return false;
//     }
//     return true;
// }
