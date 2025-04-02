/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-noe.carabin
** File description:
** error_detector.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"

int char_detector(char c, int nbr)
{
    if (((c < '0' || c > '9') && c != '\n')) {
        my_putstr("File must only content '.' and 'o'");
        return (84);
    } else {
        return 0;
    }
}

static void open_read_next(struct moving_string *str, struct stat *buf,
    int count, int file_size)
{
    int len = 0;

    str->string = malloc(sizeof(char) * (file_size - count + 1));
    len = read(str->file_origin, str->string, buf->st_size - (count + 1));
    str->string[len] = '\0';
    str->cpt = 0;
    init_struct(str, buf, count);
    close(str->file_origin);
}

int open_and_read(char *filepath, struct moving_string *str)
{
    struct stat buf;
    int file_size = 0;
    char letter;
    int count = 0;

    str->file_origin = open(filepath, O_RDONLY);
    letter = '\t';
    if (str->file_origin == (-1)) {
        my_putstr("Filepath is incorect");
        str->error = 84;
        return 84;
    }
    stat(filepath, &buf);
    file_size = buf.st_size;
    for (; letter != '\n'; count++) {
        read(str->file_origin, &letter, 1);
        if (char_detector(letter, str->error) == 84)
            return 84;
    }
    open_read_next(str, &buf, count, file_size);
}

int main(int ac, char **av)
{
    struct moving_string str;

    str.error = 0;
    if (ac == 2)
        open_and_read(av[1], &str);
    if (ac == 3)
        if (argument_selector(av[1], av[2], &str) == 84)
            return 84;
    if (ac != 2 && ac != 3) {
        my_putstr("Invalid inpout");
        return (84);
    }
    if (str.error == 84)
        return (84);
    write(1, str.string, str.final_size);
    if (ac == 2)
        write(1, "\n", 1);
    free(str.string);
    return (0);
}
