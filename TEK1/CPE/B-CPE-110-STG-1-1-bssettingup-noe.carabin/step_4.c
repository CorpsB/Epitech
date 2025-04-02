/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-bssettingup-noe.carabin
** File description:
** step_4.c
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

void fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer;
    int size = x;
    int a = open(filepath, O_RDONLY);
    int b = read(filepath, buffer, size);

    my_putstr(buffer);
    close(filepath);
}
