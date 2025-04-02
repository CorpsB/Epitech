/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** l_file
*/

#include "../../../include/shell.h"

int is_file_in_files(file_t *files, char *data)
{
    file_t *tmp = files;

    for (; tmp != NULL; tmp = tmp->next){
        if (my_strcmp(tmp->data, data) == 0)
            return 1;
    }
    return 0;
}

void add_file(file_t **files, int type, char *name)
{
    file_t *file = malloc(sizeof(file_t));

    file->data = my_strdup(name);
    file->is_dir = type;
    file->next = *files;
    *files = file;
}

void free_files(file_t **files)
{
    file_t *target;
    file_t *tmp = *files;

    while (tmp != NULL){
        target = tmp;
        free(tmp->data);
        tmp = tmp->next;
        free(target);
    }
}
