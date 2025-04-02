/*
** EPITECH PROJECT, 2024
** LOAD
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../../include/amazed.h"

static int set_start_or_end_flag(labyrinth_t *laby, char *name,
    int mode, int nb[2])
{
    if (mode == 1){
        if (laby->start != NULL)
            return -1;
        my_putstr("##start\n", 1);
    }
    if (mode == 2){
        if (laby->end != NULL)
            return -1;
        my_putstr("##end\n", 1);
    }
    if (laby->rooms == NULL)
        my_putstr("#rooms\n", 1);
    add_room_to_list(&laby->rooms, name, nb[0], nb[1]);
    if (mode == 1)
        laby->start = laby->rooms;
    if (mode == 2)
        laby->end = laby->rooms;
    my_printf("%s %d %d\n", name, nb[0], nb[1]);
    return 0;
}

static int get_pos_coords(int i, int j, char *line, int nb[2])
{
    i = j + 1;
    j = skip_word(line, i);
    nb[0] = n_convert_s(line, i);
    if (j - i != n_size(nb[0]))
        return -1;
    i = j + 1;
    j = skip_word(line, i);
    nb[1] = n_convert_s(line, i);
    if (j - i != n_size(nb[1]))
        return -1;
    return 0;
}

static int store_room_data(labyrinth_t *laby, char *line, int i, int mode)
{
    int j = skip_word(line, i);
    char *name = my_substr(line, i, j);
    int nb[2];

    if (get_pos_coords(i, j, line, nb) == -1){
        free(name);
        return -1;
    }
    for (room_list_t *tmp = laby->rooms; tmp != NULL; tmp = tmp->next){
        if (my_strcmp(tmp->name, name) == 0 ||
        (tmp->pos_x == nb[0] && tmp->pos_y == nb[1])){
            free(name);
            return -1;
        }
    }
    return set_start_or_end_flag(laby, name, mode, nb);
}

int store_room(labyrinth_t *laby, char *line, int i, int mode)
{
    if (laby->nb_robots == -1 || laby->tunnel_count != 0)
        return -1;
    return store_room_data(laby, line, i, mode);
}
