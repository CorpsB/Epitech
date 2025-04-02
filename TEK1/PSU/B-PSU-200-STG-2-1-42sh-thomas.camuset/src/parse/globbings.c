/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** globbings
*/

#include "../../include/shell.h"

static int interog_is_good(char *entry, char *str)
{
    if (strlen(entry) != strlen(str))
        return 0;
    for (int i = 0; entry[i] != '\0'; i++){
        if (str[i] == '?')
            continue;
        if (str[i] != entry[i])
            return 0;
    }
    return 1;
}

static char *compact_asterisk(char *str)
{
    char *result = NULL;
    int length = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '*' && str[i] != '*' && str[i] != '\0')
            length++;
        if (str[i] != '*')
            length++;
    }
    result = malloc(sizeof(char) * (length + 1));
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != '*' || (str[i] == '*' && str[i + 1] != '*'))
            result[j] = str[i];
        if (str[i] == '*' && str[i + 1] == '*')
            j--;
        j++;
    }
    result[j] = '\0';
    return result;
}

static int asterisk_is_good_next(char *str, char *entry, int i, int *j)
{
    if (str[i] == '*'){
        for (; entry[*j] != str[i + 1] && entry[*j] != '\0'; (*j)++);
        (*j)--;
    }
}

static int asterisk_is_good(char *entry, char *str_)
{
    char *str = compact_asterisk(str_);
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++){
        asterisk_is_good_next(str, entry, i, &j);
        if (entry[j] != str[i] && str[i] != '*')
            return interog_is_good(entry, str_);
        j++;
    }
    return 1;
}

static char *parse_content(cmd_data_t *cmd)
{
    DIR *dir;
    struct dirent *d;
    file_data_t f_data;
    char *str = my_strdup(cmd->value);

    free(cmd->value);
    cmd->value = my_strdup("");
    f_data = get_file_data(str, 1);
    dir = opendir(f_data.directory);
    if (dir == NULL)
        return str;
    d = readdir(dir);
    while (d != NULL){
        if (asterisk_is_good(d->d_name, str)){
            cmd->value = my_strcat(cmd->value, " ");
            cmd->value = my_strcat(cmd->value, d->d_name);
        }
        d = readdir(dir);
    }
    return str;
}

void parse_globbings(cmd_data_t **data)
{
    cmd_data_t *tmp = *data;

    tmp = tmp->next;
    for (; tmp != NULL; tmp = tmp->next)
        tmp->value = parse_content(tmp);
    tmp = *data;
}
