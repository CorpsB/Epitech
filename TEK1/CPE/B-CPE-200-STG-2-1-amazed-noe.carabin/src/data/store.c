/*
** EPITECH PROJECT, 2024
** STORE
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../include/amazed.h"

static int set_start_end_point(labyrinth_t *laby, int mode, int i)
{
    char *line = get_data();
    int err_code;

    if (line == NULL)
        return -1;
    i = skip_comment(line, 0, &mode);
    err_code = store_room(laby, line, i, mode);
    free(line);
    return err_code;
}

int store_data(labyrinth_t *laby, char *line)
{
    int mode = 0;
    int i = skip_comment(line, 0, &mode);
    int nb_words;

    if (line[i] == '\0')
        return 0;
    if (mode != 0)
        return set_start_end_point(laby, mode, i);
    nb_words = s_count_double(line, ' ', '\t');
    if (nb_words == 3)
        return store_room(laby, line, i, mode);
    if (nb_words == 1)
        if (s_search(line, '-', '-') == -1)
            return store_nb_robot(laby, line, i);
        else
            return store_link(laby, line, i);
    return -1;
}
