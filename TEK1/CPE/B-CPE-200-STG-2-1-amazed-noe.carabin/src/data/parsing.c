/*
** EPITECH PROJECT, 2024
** STORE
** File description:
** Reads all the stdin input and store it into the system's linked list.
*/

#include "../../include/amazed.h"

static int is_spe_room_define(char *line, int *i, int *mode)
{
    ++(*i);
    if (my_strscmp(line, "#start", *i, 6) == 0)
        *mode = 1;
    else if (my_strscmp(line, "#end", *i, 4) == 0)
        *mode = 2;
    if (*mode == 0)
        for (; line[*i] != '\0'; ++(*i));
}

int skip_comment(char *line, int i, int *mode)
{
    for (; line[i] == ' ' || line[i] == '\t'; ++i);
    if (line[i] == '#')
        is_spe_room_define(line, &i, mode);
    return i;
}

int skip_word(char *line, int i)
{
    for (; line[i] != ' ' && line[i] != '\t' &&
    line[i] != '#' && line[i] != '\0'; ++i);
    return i;
}
