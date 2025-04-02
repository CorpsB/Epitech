/*
** EPITECH PROJECT, 2023
** MY_STRTOK
** File description:
** Create a place into the memory for the given string.
*/

#include "../../../include/shell.h"

static int is_char_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == c)
            return 1;
    return 0;
}

static int skip_word(char *str, char *list, int i)
{
    for (; !is_char_in_str(list, str[i]) && str[i] != '\0'; ++i);
    return i;
}

static void save_word(char **res, char *str, int i, int j)
{
    char *tmp;

    tmp = my_substr(str, j, i);
    *res = s_sependmerge(*res, tmp, ' ');
    free(tmp);
}

static int skip_guillemet(char *str, int i)
{
    ++i;
    if (str[i - 1] == '"'){
        for (; str[i] != '"' && str[i] != '\0'; ++i);
        return i;
    }
    if (str[i - 1] == '\'')
        for (; str[i] != '\'' && str[i] != '\0'; ++i);
    return i;
}

char *my_strtok(char *str, char *clean_list)
{
    char *res = my_strdup("");
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        j = i;
        if (!is_char_in_str(clean_list, str[i]) && str[i] != '"' &&
        str[i] != '\''){
            i = skip_word(str, clean_list, i);
            save_word(&res, str, j, i);
        }
        if (str[i] != '"' && str[i] != '\'')
            continue;
        i = skip_guillemet(str, i);
        save_word(&res, str, j, i + 1);
        if (str[i] == '\0')
            break;
    }
    if (res[0] != '\0')
        res[my_strlen(res) - 1] = '\0';
    return res;
}

char *my_origin_strtok(char *str, char *clean_list)
{
    char *res = my_strdup("");
    char *tmp;
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        j = i;
        if (!is_char_in_str(clean_list, str[i])){
            i = skip_word(str, clean_list, i);
            tmp = my_substr(str, j, i);
            res = s_sependmerge(res, tmp, ' ');
            free(tmp);
        }
        if (str[i] == '\0')
            break;
    }
    res[my_strlen(res) - 1] = '\0';
    return res;
}
