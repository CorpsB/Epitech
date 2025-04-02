/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** s_clean
*/

#include "../../../include/base/my.h"

static void add_char_to_str(char **str, char c, int *i)
{
    (*str)[*i] = c;
    (*i)++;
}

static void add_space(char *str, char **cleaned_str, int i, int *index)
{
    int is_letter = 0;
    char c = str[i + 1];

    for (int j = i + 1; str[j] != '\0'; j++)
        if (str[j] != ' ' && str[j] != '\t')
            is_letter = 1;
        if (is_letter && (c != '\0' && (c == ' ' || c == '\t')))
            add_char_to_str(cleaned_str, ' ', index);
}

static char *clean_str_next(char *str)
{
    int length = 0;
    char *cleaned_str = NULL;
    int index = 0;

    length = my_strlen(str);
    cleaned_str = malloc(sizeof(char) * (length + 1));
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' ' && str[i] != '\t'){
            add_char_to_str(&cleaned_str, str[i], &index);
            add_space(str, &cleaned_str, i, &index);
        }
    }
    cleaned_str[index] = '\0';
    return cleaned_str;
}

char *s_clean(char *str)
{
    int is_only_space = 1;

    if (str == NULL)
        return my_strdup(" ");
    for (int i = 0; str[i] != '\0'; i++){
        if (!is_only_space)
            break;
        if (str[i] != ' ' && str[i] != '\t')
            is_only_space = 0;
    }
    if (is_only_space)
        return my_strdup(" ");
    return clean_str_next(str);
}
