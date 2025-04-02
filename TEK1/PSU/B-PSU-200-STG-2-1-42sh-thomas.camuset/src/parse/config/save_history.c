/*
** EPITECH PROJECT, 2024
** HISTORY
** File description:
** Save or load history content into .history file.
*/

#include "../../../include/shell.h"

void load_history_line(history_t **history, char *line)
{
    int hash = s_search(line, '#', '#');

    if (hash == -1)
        return;
    l_add_history(history, my_substr(line, hash + 1,
    my_strlen(line)), my_substr(line, 0, hash));
}

void load_history(history_t **history)
{
    char *file = my_readfile(".history");
    char *buff = NULL;

    if (file == NULL)
        return;
    for (int i = 0; file[i] != '\0';){
        buff = my_getline(file, &i, '\n');
        load_history_line(history, buff);
        free(buff);
    }
    free(file);
}

void save_history(history_t **history)
{
    int fd = open(".history", O_WRONLY | O_TRUNC | O_CREAT, 0666);

    l_reverse_history(history);
    for (history_t *tmp = (*history)->next; tmp != NULL; tmp = tmp->next){
        my_putstr(tmp->temps, fd);
        my_putchar('#', fd);
        my_putstr(tmp->cmd_line, fd);
        my_putchar('\n', fd);
    }
    close(fd);
}
