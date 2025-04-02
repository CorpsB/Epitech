/*
** EPITECH PROJECT, 2024
** LOAD
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../include/amazed.h"

char *get_data(void)
{
    char *buff = NULL;
    size_t size = 0;
    int m_pos;

    if (getline(&buff, &size, stdin) == -1){
        free(buff);
        return NULL;
    }
    m_pos = my_strlen(buff) - 1;
    if (buff[m_pos] == '\n')
        buff[m_pos] = '\0';
    return buff;
}

static int is_missing_arguments(labyrinth_t *laby)
{
    int is_pipe = 0;

    if (laby->nb_robots == -1 || laby->rooms == NULL ||
    laby->start == NULL || laby->end == NULL)
        return 1;
    for (room_list_t *tmp = laby->rooms; tmp != NULL; tmp = tmp->next)
        if (tmp->list != NULL)
            is_pipe = 1;
    if (is_pipe == 0)
        return 1;
    return 0;
}

int load_data(labyrinth_t *laby)
{
    int err_code = 84;

    for (char *line = get_data(); line != NULL; line = get_data()){
        err_code = store_data(laby, line);
        free(line);
        if (err_code != 0){
            err_code = 84;
            break;
        }
    }
    if (is_missing_arguments(laby))
        return 127;
    return err_code;
}
