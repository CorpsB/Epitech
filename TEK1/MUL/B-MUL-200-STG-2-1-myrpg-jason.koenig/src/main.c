/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/csfml.h"
#include <sys/stat.h>

int menu(sfRenderWindow *window)
{
    gui_t gui;
    int err_code = 0;

    init_gui(&gui, window);
    while (sfRenderWindow_isOpen(window) && err_code == 0){
        while (sfRenderWindow_pollEvent(window, &gui.events))
            analyse_events(&gui);
        sfRenderWindow_clear(window, sfBlack);
        err_code = update_gui(&gui);
        sfRenderWindow_display(window);
    }
    destroy_gui(&gui, sfTrue);
    return err_code;
}

int help_func(void)
{
    int nbr = open("README.md", O_RDONLY);
    struct stat information;
    char *message;

    stat("README.md", &information);
    message = malloc(sizeof(char) * (information.st_size + 1));
    read(nbr, message, information.st_size);
    write(1, message, information.st_size);
    close(nbr);
    free(message);
    return 0;
}

int main(int ac, char **av)
{
    sfRenderWindow *window;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return help_func();
    window = create_window();
    sfListener_setGlobalVolume((float)50);
    return menu(window);
}
