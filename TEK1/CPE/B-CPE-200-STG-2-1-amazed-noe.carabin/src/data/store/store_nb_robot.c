/*
** EPITECH PROJECT, 2024
** LOAD
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../../include/amazed.h"

int store_nb_robot(labyrinth_t *laby, char *line, int i)
{
    int j;
    int nb_robots;

    if (laby->rooms != NULL || laby->tunnel_count != 0 ||
    laby->nb_robots != -1)
        return -1;
    nb_robots = n_convert_s(line, i);
    if (nb_robots < 1)
        return -1;
    j = skip_word(line, i);
    if (j - i != n_size(nb_robots))
        return -1;
    laby->nb_robots = nb_robots;
    my_putstr("#number_of_robots\n", 1);
    my_printf("%d\n", nb_robots);
    return 0;
}
