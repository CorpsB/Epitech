/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/project.h"

static void get_vit_by_rose(direction_t *dir, float vit)
{
    char buff_vit[50];

    if (vit != dir->vit){
        dir->vit = vit;
        sprintf(buff_vit, "%.3f", dir->vit);
        send_move("CAR_FORWARD", buff_vit);
    }
}

static float set_dir_by_vit(int rose_line, int maria_line,
    int multi, float vit)
{
    if (vit < 0.3)
        return ((1 - (rose_line / 3500.0)) * 0.25 +
        (1 - (maria_line / 3500.0)) * 0.08) * multi;
    if (vit < 0.5)
        return ((1 - (rose_line / 3500.0)) * 0.23 +
        (1 - (maria_line / 3500.0)) * 0.08) * multi;
    return ((1 - (rose_line / 3500.0)) * 0.23 +
    (1 - (maria_line / 3500.0)) * 0.07) * multi;
}

static void get_dir_by_dist(int side, int op_side, direction_t *dir, int multi)
{
    int rose_line = get_third_side(side, dir->forward, 30);
    int maria_line = get_third_side(side, op_side, 60);
    float vit = (rose_line > 4000 && side + 20 > dir->pist_length &&
    op_side + 20 > dir->pist_length && dir->pist_length > 400) ? 0.7 : 0.2;

    vit = (dir->pist_length < 400) ? 0.4 : vit;
    get_vit_by_rose(dir, vit);
    if (abs(side - op_side) < 250 && dir->forward > 2000){
        dir->dir = 0;
        return;
    }
    maria_line = (maria_line > 3500) ? 3500 : maria_line;
    rose_line = (rose_line > 3500) ? 3500 : rose_line;
    dir->dir = set_dir_by_vit(rose_line, maria_line, multi, vit);
    if (maria_line < 1000 && dir->pist_length > 400)
        dir->dir *= 1.6;
    if (maria_line < 600 && rose_line < 600 && dir->pist_length > 400)
        dir->all_dir = 1;
}

void get_new_dir(direction_t *dir)
{
    char buff_dir[50];
    int last_dir = dir->dir;

    if (dir->left < dir->right)
        get_dir_by_dist(dir->left, dir->right, dir, -1);
    else
        get_dir_by_dist(dir->right, dir->left, dir, 1);
    if (dir->dir != last_dir){
        sprintf(buff_dir, "%.3f", dir->dir);
        send_move("WHEELS_DIR", buff_dir);
    }
}
