/*
** EPITECH PROJECT, 2023
** WINDOW HANDLER
** File description:
** Do window things.
*/

#include "../include/csfml.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1366, 768, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void delete_window(sfRenderWindow *window)
{
    if (sfRenderWindow_isOpen(window))
        sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}
