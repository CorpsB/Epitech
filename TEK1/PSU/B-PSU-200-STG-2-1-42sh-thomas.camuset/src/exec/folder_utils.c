/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** folder_utils
*/

#include "../../include/shell.h"

static void directory_printing(file_t *file)
{
    if (file->is_dir == 1)
        my_printf("%s/  ", (char *)file->data);
    else
        my_printf("%s  ", (char *)file->data);
}

int count_files_in_folder(file_t *files)
{
    int counter = 0;
    file_t *tmp = files;

    for (; tmp != NULL; tmp = tmp->next)
        counter++;
    return counter;
}

void fill_files(file_t **files, char *folder, char *f_name)
{
    DIR *dir;
    struct dirent *d;
    char w_dir[1000];

    getcwd(w_dir, 1000);
    if (my_strlen(folder) < 1)
        dir = opendir(w_dir);
    else
        dir = opendir(folder);
    if (dir == NULL)
        return;
    d = readdir(dir);
    while (d != NULL){
        if (my_strncmp(d->d_name, f_name, my_strlen(f_name)) == 0 &&
            !is_file_in_files(*files, d->d_name))
            add_file(files, d->d_type == 4, d->d_name);
        d = readdir(dir);
    }
    closedir(dir);
}

void display_files(file_t *files)
{
    file_t *tmp = files;

    my_putstr("\n", 1);
    for (; tmp != NULL; tmp = tmp->next)
        directory_printing(tmp);
    my_putstr("\b\b\n", 1);
}
