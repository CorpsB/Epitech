/*
** EPITECH PROJECT, 2024
** OPEN_RC
** File description:
** Open 42shrc file and store his content after parsing it.
*/

#include "../../../include/shell.h"

static int skip_space(char *str, int i)
{
    for (; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; ++i);
    return i;
}

int open_line_rc(storage_bag_t *storage, char *line)
{
    int i = skip_space(line, 0);

    if (line[i] == '#' || line[i] == '\0')
        return 0;
    return run_command(storage, &line[i]);
}

int open_rc(storage_bag_t *storage)
{
    char *file = my_readfile(".42shrc");
    char *buff = NULL;
    int exit_code = 0;

    if (file == NULL)
        return 0;
    for (int i = 0; file[i] != '\0';){
        buff = my_getline(file, &i, '\n');
        exit_code = open_line_rc(storage, buff);
        free(buff);
    }
    free(file);
    return exit_code;
}
