/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell1-noe.carabin-main
** File description:
** format_str.c
*/

#include "../my.h"

// static char *delete_first(char *str)
// {
//     if (str[0] == '\t') {
//         for (int i = 0;str[i] == '\t'; i++)
//             str[i] = 130;
//         return str;
//     }
//     return str;
// }

static int len_without_other_char(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == 130) {
            i++;
            continue;
        }
        i++;
        count++;
    }
    return count;
}

static char *copy_without_other_char(char *result, char *src)
{
    int r_count = 0;

    for (int s_count = 0; src[s_count] != '\0'; s_count++) {
        if (src[s_count] == -126)
            continue;
        result[r_count] = src[s_count];
        r_count++;
    }
    result[r_count] = '\0';
    return result;
}

static char *delete_end(char *str)
{
    int i = 0;
    bool is_exec = false;

    for (; str[i] != '\0'; i++)
        if (str[i] != '\t' && !is_exec)
            is_exec = true;
    if (!is_exec)
        return NULL;
    i--;
    for (; i > 0; i--) {
        if (str[i] == '\t') {
            str[i] = 130;
            continue;
        }
        break;
    }
    return str;
}

static bool is_exec(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] != '\t' && str[i] != '\n')
            return true;
    return false;
}

/**
 * Cette fonction prend une string et supprime tout les '\t' et ' '.
*/
char *format_str(char *str)
{
    char *result;

    if (!is_exec(str))
        return (my_strdup(""));
    str = delete_end(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = 130;
    }
    result = malloc(sizeof(char) * (len_without_other_char(str) + 1));
    copy_without_other_char(result, str);
    free(str);
    return result;
}
