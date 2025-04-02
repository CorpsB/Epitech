/*
** EPITECH PROJECT, 2024
** MY_STR_TO_WORD_ARRAY
** File description:
** Transform a string into an array.
*/

#include "../../../include/my.h"

static int malloc_tab(char ***mem_tab, char *str, char sep)
{
    int nwords = s_count(str, sep);

    if (nwords == 0)
        return -1;
    *mem_tab = malloc(sizeof(char *) * (nwords + 1));
    if (*mem_tab == NULL)
        return -1;
    return 0;
}

static int is_sep_after(char *str, char sep, int pos[3])
{
    if (str[pos[1]] != sep && str[pos[1] + 1] == sep &&
    str[pos[1] + 1] != '\0')
        return 1;
    return 0;
}

static int is_sep_before(char *str, char sep, int pos[3])
{
    if (pos[1] == 0)
        return 1;
    if (str[pos[1]] != sep && str[pos[1] - 1] == sep)
        return 1;
    return 0;
}

static void move_pointer(char *str, char sep, char **tab, int (*pos)[3])
{
    for (; str[(*pos)[1]] == sep || (str[(*pos)[1]] == '\0'
    && (str[(*pos)[1] - 1] == sep)); --(*pos)[1]);
    if (str[my_strlen(str) - 1] != sep){
        tab[(*pos)[2]] = my_substr(str, (*pos)[0], (*pos)[1] + 1);
        (*pos)[2]++;
    }
    tab[(*pos)[2]] = NULL;
}

char **a_convert_s(char *str, char sep)
{
    int pos[] = {0, 0, 0};
    char **tab;

    if (malloc_tab(&tab, str, sep) == -1)
        return NULL;
    for (; str[pos[1]] == sep; ++pos[1])
        ++pos[0];
    for (; str[pos[1]] != '\0'; ++pos[1]){
        if (is_sep_before(str, sep, pos) == 1)
            pos[0] = pos[1];
        if (is_sep_after(str, sep, pos) == 1){
            tab[pos[2]] = my_substr(str, pos[0], pos[1] + 1);
            pos[2]++;
            pos[0] = pos[1] + 1;
        }
    }
    move_pointer(str, sep, tab, &pos);
    return tab;
}
