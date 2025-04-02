/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** classes
*/

#include "../../../include/csfml.h"

void become_knight(battler_t *stats, int id)
{
    if (id == KNIGHT1){
        stats->health += 2;
        stats->attack += 1;
        stats->defense += 2;
        return;
    }
    if (id == KNIGHT2){
        stats->health += 1;
        stats->attack += 2;
        stats->defense += 2;
        return;
    }
    if (id == KNIGHT3){
        stats->health += 1;
        stats->defense += 4;
    }
}

void become_assassin(battler_t *stats, int id)
{
    if (id == ASSASSIN1){
        stats->attack += 3;
        stats->luck += 2;
        return;
    }
    if (id == ASSASSIN2){
        stats->attack += 3;
        stats->luck += 2;
        return;
    }
    if (id == ASSASSIN3){
        stats->health += 1;
        stats->attack += 1;
        stats->luck += 3;
    }
}

void become_swordsman(battler_t *stats, int id)
{
    if (id == SWORDSMAN1){
        stats->attack += 2;
        stats->defense += 1;
        stats->luck += 2;
        return;
    }
    if (id == SWORDSMAN2){
        stats->attack += 1;
        stats->defense += 1;
        stats->luck += 3;
        return;
    }
    if (id == SWORDSMAN3){
        stats->attack += 2;
        stats->defense += 2;
        stats->luck += 1;
    }
}

void become_dragon_hunter(battler_t *stats, int id)
{
    if (id == DARGON_HUNTER1){
        stats->health += 3;
        stats->attack += 2;
        return;
    }
    if (id == DARGON_HUNTER2){
        stats->health += 2;
        stats->attack += 1;
        stats->defense += 2;
        return;
    }
    if (id == DARGON_HUNTER3){
        stats->health += 2;
        stats->attack += 2;
        stats->defense += 1;
    }
}
