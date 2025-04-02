/*
** EPITECH PROJECT, 2023
** B-CPE-100-STG-1-1-cpoolday12-thomas.camuset
** File description:
** main
*/

#include "./includes/my.h"
#include "./includes/paint.h"

static int help_function(char *something)
{
    int nbr = open("text/help.txt", O_RDONLY);
    struct stat information;
    char *message;

    stat("text/help.txt", &information);
    message = malloc(sizeof(char) * (information.st_size + 1));
    read(nbr, message, information.st_size);
    write(1, message, information.st_size);
    close(nbr);
    free(message);
    return 0;
}

int main(int ac, char **av)
{
    paint_t paint;

    if (ac >= 3)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return help_function(av[1]);
    if (ac == 1)
        init_paint(&paint, 0, "");
    else
        init_paint(&paint, 1, av[1]);
    while (sfRenderWindow_isOpen(paint.window)){
        paint.scale = get_window_scale(&paint);
        event_handler(&paint);
        draw_paint(&paint);
    }
    destroy_paint(&paint);
    free_drop_menus(&paint);
}
