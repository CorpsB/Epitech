/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** get_info.c
*/

#include "my.h"

static char *date_converion(struct stat *tmp_info)
{
    char *str = malloc(sizeof(char) * 13);
    char *time = ctime(&tmp_info->st_mtime);
    char number;
    char num;

    for (int i = 4; i < 17; i++) {
        str[i - 4] = time[i];
    }
    str[12] = '\0';
    return str;
}

static void write_info(each_info_t **filepath, struct dirent *entry)
{
    linked_info_t *one_node = malloc(sizeof(linked_info_t));
    struct stat tmp_info;
    struct passwd *author_name;
    struct group *author_group;

    stat(my_strstr((*filepath)->filepath, entry->d_name, '/'), &tmp_info);
    author_name = getpwuid(tmp_info.st_uid);
    author_group = getgrgid(tmp_info.st_gid);
    one_node->name = my_strdup(entry->d_name);
    one_node->link = tmp_info.st_nlink;
    one_node->author = author_name->pw_name;
    one_node->author_group = author_group->gr_name;
    one_node->date = my_strdup(date_converion(&tmp_info));
    one_node->size = tmp_info.st_size;
    one_node->rules = file_type(&tmp_info);
    one_node->time = tmp_info.st_mtime;
    one_node->block = tmp_info.st_blocks;
    one_node->next = (*filepath)->info;
    (*filepath)->info = one_node;
}

static int get_info(char *filepath, each_info_t *info)
{
    DIR *actual_file = opendir(filepath);
    struct dirent *entry;

    if (actual_file == NULL)
        return 84;
    entry = readdir(actual_file);
    for (; entry != NULL; entry = readdir(actual_file)) {
        write_info(&info, entry);
    }
    closedir(actual_file);
}

static void put_linked(each_info_t *tmp)
{
    linked_info_t *infos = malloc(sizeof(linked_info_t));

    infos = NULL;
    tmp->info = infos;
}

int each_filepath(each_info_t *filepath)
{
    each_info_t *tmp2 = filepath;

    while (tmp2 != NULL) {
        put_linked(tmp2);
        get_info(tmp2->filepath, tmp2);
        tmp2 = tmp2->next;
    }
    return 0;
}
