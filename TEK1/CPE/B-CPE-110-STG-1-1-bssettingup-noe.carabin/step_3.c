/*
** EPITECH PROJECT, 2023
** ncarabin
** File description:
** step_3.c
*/

#include <fcntl.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i = i + 1) {
        my_putchar(str[i]);
    }
}

void fs_cat_500_bytes(char const *filepath)
{
    char *buffer;
    int size = 500;
    int a = open(filepath, O_RDONLY);
    int b = read(fd, buffer, size);

    my_putstr(buffer);
    close(filepath);
}
