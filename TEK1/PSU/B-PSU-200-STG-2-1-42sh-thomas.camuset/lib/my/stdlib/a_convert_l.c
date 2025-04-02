/*
** EPITECH PROJECT, 2024
** MY_STR_TO_WORD_ARRAY
** File description:
** Transform a string into an array.
*/

#include "../../../include/shell.h"

static int malloc_tab(char ***mem_tab, char *str, char sep, char sep2)
{
    int nwords = s_count(str, sep, sep2);

    if (nwords == 0)
        return -1;
    *mem_tab = malloc(sizeof(char *) * (nwords + 1));
    return 0;
}

static int is_sep_after(char *str, char sep, char sep2, int pos[3])
{
    if (str[pos[1]] != sep && str[pos[1]] != sep2 &&
    (str[pos[1] + 1] == sep || str[pos[1] + 1] == sep2) &&
    str[pos[1] + 1] != '\0')
        return 1;
    return 0;
}

static int is_sep_before(char *str, char sep, char sep2, int pos[3])
{
    if (pos[1] == 0)
        return 1;
    if (str[pos[1]] != sep && str[pos[1]] != sep2 &&
    (str[pos[1] - 1] == sep || str[pos[1] - 1] == sep2))
        return 1;
    return 0;
}

static char *build_str(char sep, char sep2)
{
    char *str = malloc(sizeof(char) * 3);

    str[0] = sep;
    str[1] = sep2;
    str[2] = '\0';
    return str;
}

static void move_pointer(char *str, char *sepa, char **tab, int (*pos)[3])
{
    for (; str[(*pos)[1]] == sepa[0] || str[(*pos)[1]] == sepa[1] ||
    (str[(*pos)[1]] == '\0' && (str[(*pos)[1] - 1] == sepa[0] ||
    str[(*pos)[1] - 1] == sepa[1])); --(*pos)[1]);
    if (str[my_strlen(str) - 1] != sepa[0] &&
    str[my_strlen(str) - 1] != sepa[1]){
        tab[(*pos)[2]] = my_substr(str, (*pos)[0], (*pos)[1] + 1);
        (*pos)[2]++;
    }
    tab[(*pos)[2]] = NULL;
}

char **a_convert_s(char *str, char sep, char sep2)
{
    int pos[] = {0, 0, 0};
    char *sepa = build_str(sep, sep2);
    char **tab;

    if (malloc_tab(&tab, str, sepa[0], sepa[1]) == -1)
        return NULL;
    for (; str[pos[1]] == sepa[0] || str[pos[1]] == sepa[1]; ++pos[1])
        ++pos[0];
    for (; str[pos[1]] != '\0'; ++pos[1]){
        if (is_sep_before(str, sepa[0], sepa[1], pos) == 1)
            pos[0] = pos[1];
        if (is_sep_after(str, sepa[0], sepa[1], pos) == 1){
            tab[pos[2]] = my_substr(str, pos[0], pos[1] + 1);
            pos[2]++;
            pos[0] = pos[1] + 1;
        }
    }
    move_pointer(str, sepa, tab, &pos);
    free(sepa);
    return tab;
}
