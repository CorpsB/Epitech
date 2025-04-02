/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-mypaint-noe.carabin
** File description:
** music_manager
*/

#include "../includes/my.h"
#include "../includes/paint.h"

void music_manager(paint_t *paint)
{
    sfMusic_setLoop(paint->music, sfTrue);
    sfMusic_setVolume(paint->music, 30.0);
    sfMusic_play(paint->music);
}
