/*
** EPITECH PROJECT, 2024
** LOAD
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../../include/amazed.h"

static int is_valid_link(char *name, char *name2, char *line,
    labyrinth_t *laby)
{
    room_list_t *a = NULL;
    room_list_t *b = NULL;

    for (room_list_t *tmp = laby->rooms; tmp != NULL; tmp = tmp->next){
        if (my_strcmp(tmp->name, name) == 0)
            a = tmp;
        if (my_strcmp(tmp->name, name2) == 0)
            b = tmp;
    }
    if (a == NULL || b == NULL)
        return -1;
    if (laby->tunnel_count == 0)
        my_putstr("#tunnels\n", 1);
    add_room_link(a, b);
    ++laby->tunnel_count;
    my_printf("%s-%s\n", name, name2);
    return 0;
}

static int store_link_data(labyrinth_t *laby, char *line, int i)
{
    int j = s_search(line, '-', '-');
    char *name = my_substr(line, i, j);
    char *name2;
    int err_code;

    i = j + 1;
    j = skip_word(line, i);
    name2 = my_substr(line, i, j);
    err_code = is_valid_link(name, name2, line, laby);
    free(name);
    free(name2);
    if (err_code == -1)
        return -1;
    return 0;
}

int store_link(labyrinth_t *laby, char *line, int i)
{
    if (laby->rooms == NULL || laby->nb_robots == -1)
        return -1;
    return store_link_data(laby, line, i);
}
