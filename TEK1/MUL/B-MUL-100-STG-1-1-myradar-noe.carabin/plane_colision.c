/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-noe.carabin
** File description:
** plane_colision.c
*/

#include "my.h"

static bool get_collision_1(sfVector2f *center1, sfVector2f *center2,
    plane_t *p1)
{
    bool collision = true;
    float corner1_x;
    float corner1_y;

    for (int i = 0; i < 4; ++i) {
        corner1_x = p1->start_x;
        corner1_y = p1->start_y;
        if (i > 1)
            corner1_x += 20;
        if (i % 2 == 0)
            corner1_y += 20;
        if (corner1_x >= center2->x - 0.5 * 20 &&
        corner1_x <= center2->x + 0.5 * 20 &&
        corner1_y >= center2->y - 0.5 * 20 &&
        corner1_y <= center2->y + 0.5 * 20){
            collision = false;
            break;
        }
    }
    return (collision);
}

static bool get_collision_2(sfVector2f *center1, sfVector2f *center2,
    plane_t *p2)
{
    bool collision = true;
    float corner2_x;
    float corner2_y;

    for (int i = 0; i < 4; ++i){
        corner2_x = p2->start_x;
        corner2_y = p2->start_y;
        if (i > 1)
            corner2_x += 20;
        if (i % 2 == 0)
            corner2_y += 20;
        if (corner2_x >= center1->x - 0.5 * 20 &&
        corner2_x <= center1->x + 0.5 * 20 &&
        corner2_y >= center1->y - 0.5 * 20 &&
        corner2_y <= center1->y + 0.5 * 20){
            collision = false;
            break;
        }
    }
    return (collision);
}

void check_corner_collision(plane_t *p1, plane_t *p2)
{
    sfVector2f center1;
    sfVector2f center2;
    bool collision = true;

    if (p1->id == p2->id || !p2->isalive)
        return;
    center1.x = p1->start_x + 0.5 * 20;
    center1.y = p1->start_y + 0.5 * 20;
    center2.x = p2->start_x + 0.5 * 20;
    center2.y = p2->start_y + 0.5 * 20;
    collision = get_collision_1(&center1, &center2, p1);
    if (!collision)
        collision = get_collision_2(&center1, &center2, p2);
    p1->isalive = collision;
    p2->isalive = collision;
}

void check_colision(plane_t *plane, game_t *game)
{
    plane_t *actual = plane;
    plane_t *checker;

    for (; actual != NULL; actual = actual->next){
        checker = plane;
        if (!actual->isalive)
            continue;
        for (; checker != NULL; checker = checker->next)
            check_corner_collision(actual, checker);
    }
}
