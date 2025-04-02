/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-noe.carabin
** File description:
** recursive_flag.c
*/

#include "my.h"
#include <string.h>

char *my_strstr(char *src, char *se, char separator)
{
    char *result = malloc(sizeof(char) * (my_strlen(src) + my_strlen(se) + 2));
    int index = 0;
    bool first = false;

    for (int i = 0; src[i] != '\0'; i++) {
        result[index] = src[i];
        index++;
    }
    result[index] = separator;
    index++;
    for (int i = 0; se[i] != '\0'; i++) {
        result[index] = se[i];
        index++;
    }
    result[index] = '\0';
    return result;
}

static bool nether(char *str, each_info_t **list)
{
    each_info_t *tmp = *list;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->filepath, str) == 1)
            return false;
    }
    return true;
}

static bool big_if(char *pat, each_info_t **list, struct stat *inf,
    struct dirent *ent)
{
        if (S_ISDIR(inf->st_mode) && my_strcmp(ent->d_name, ".") == 0
        && my_strcmp(ent->d_name, "..") == 0 &&
        nether(my_strstr(pat, ent->d_name, '/'), list))
            return true;
        return false;
}

static int get_dir(char *pat, each_info_t **list, flag_t *flag)
{
    DIR *ac = opendir(pat);
    struct stat inf;
    struct dirent *ent;

    if (ac == NULL)
        return 84;
    ent = readdir(ac);
    for (; ent != NULL; ent = readdir(ac)) {
        stat(my_strstr(pat, ent->d_name, '/'), &inf);
        if (!flag->flag_a && big_if(pat, list, &inf, ent) &&
        ent->d_name[0] != '.') {
            my_put_in_list(list, my_strstr(pat, ent->d_name, '/'));
            return 1;
        }
        if (flag->flag_a && big_if(pat, list, &inf, ent)) {
            my_put_in_list(list, my_strstr(pat, ent->d_name, '/'));
            return 1;
        }
    }
    return 0;
}

int recursive_flag(each_info_t **filepath, flag_t *flag)
{
    int error = 0;
    each_info_t *tmp = *filepath;
    int index = my_list_size(*filepath);

    for (int i = 0; i < index; i++) {
        tmp = *filepath;
        for (int a = 0; a < i; tmp = tmp->next)
            a++;
        error = get_dir(tmp->filepath, filepath, flag);
        if (error == 1) {
            recursive_flag(filepath, flag);
            break;
        }
        index = my_list_size(*filepath);
    }
    return 0;
}
