/*
** EPITECH PROJECT, 2024
** EXEC_CHEVRON
** File description:
** Run commands who are not implemeted.
*/

#include "../../include/shell.h"

static char *ask(storage_bag_t *storage, char *end)
{
    size_t size = 0;
    char *line = NULL;
    int b_rd;

    if (storage->is_tty == false)
        my_putstr("? ", 1);
    b_rd = getline(&line, &size, stdin);
    if (b_rd == -1){
        free(line);
        return NULL;
    }
    line[b_rd - 1] = '\0';
    if (my_strcmp(line, end) == 0){
        free(line);
        return NULL;
    }
    line[b_rd - 1] = '\n';
    return line;
}

int exec_dleft_chevron(storage_bag_t *storage, pipe_data_t *data)
{
    char *res = my_strdup("");
    int exit_code;

    for (char *r = ask(storage, data->chev_left); r != NULL;
    r = ask(storage, data->chev_left)){
        res = my_strcat(res, r);
        free(r);
    }
    exit_code = exec_pipe(storage, data->build_cmd, res);
    free(res);
    return 2 + exit_code;
}

int exec_dright_chevron(pipe_data_t *data)
{
    int fd;

    fd = open(data->chev_right, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd == -1)
        return ERR;
    if (!is_subcommand(data->build_cmd))
        dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

int exec_left_chevron(storage_bag_t *storage, pipe_data_t *data)
{
    int fd;

    if (data->mode / 10 == 1)
        return exec_dleft_chevron(storage, data);
    fd = open(data->chev_left, O_RDONLY);
    if (fd == -1)
        return ERR;
    if (!is_subcommand(data->build_cmd))
        dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}

int exec_right_chevron(pipe_data_t *data)
{
    int fd;

    if (data->mode % 10 == 1)
        return exec_dright_chevron(data);
    fd = open(data->chev_right, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
        return ERR;
    if (!is_subcommand(data->build_cmd))
        dup2(fd, STDOUT_FILENO);
    close(fd);
    return 0;
}

int exec_chevron(storage_bag_t *storage, pipe_data_t *data)
{
    int left = 0;
    int right = 0;
    char *tab[] = {storage->path_to_42sh, "-c", NULL};

    if (data->chev_left != NULL)
        left = exec_left_chevron(storage, data);
    if (data->chev_right != NULL)
        right = exec_right_chevron(data);
    if (left == ERR)
        return msg(ERR, 2, 2, data->chev_left,
        ": No such file or directory.\n");
    if (right == ERR)
        return msg(ERR, 2, 2, data->chev_right,
        ": No such file or directory.\n");
    if (data->chev_left != NULL)
        if (data->mode / 10 == 1)
            return left - 2;
    if (data->instance)
        return exec_42sh_p_pipe(storage, tab, data->build_cmd[0]);
    return run_subcommand(storage, data->build_cmd);
}
