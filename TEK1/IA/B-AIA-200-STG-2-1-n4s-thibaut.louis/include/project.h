/*
** EPITECH PROJECT, 2023
** PROJET.H
** File description:
** List of functions avaliable in the project.
*/

#ifndef PROJECT
    #define PROJECT

    #include "my.h"
    #include <stdbool.h>
    #include <math.h>

typedef struct direction {
    int left;
    int forward;
    int right;
    int pist_length;
    int all_dir;
    float dir;
    float vit;
} direction_t;

// send functions
void send_move(char *move, char *value);
float send_get_move(char *move);
void get_infos(direction_t *dir);

// calc functions
int get_average(char **table, int start, int end);
void get_new_dir(direction_t *dir);
int get_third_side(int side1, int side2, float angle);

#endif
