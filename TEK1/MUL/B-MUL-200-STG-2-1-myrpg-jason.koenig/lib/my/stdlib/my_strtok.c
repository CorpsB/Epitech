/*
** EPITECH PROJECT, 2023
** MY_STRTOK
** File description:
** Create a place into the memory for the given string.
*/

#include "../../../include/my.h"

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

char *my_strtok(char *str, char *clean_list)
{
    char *res = my_strdup("");
    char *tmp;
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        j = i;
        if (!is_char_in_str(clean_list, str[i])){
            i = skip_word(str, clean_list, i);
            tmp = my_substr(str, j, i);
            res = my_strcat_sep(res, tmp, ' ');
            free(tmp);
        }
        if (str[i] == '\0')
            break;
    }
    res[my_strlen(res) - 1] = '\0';
    return res;
}
