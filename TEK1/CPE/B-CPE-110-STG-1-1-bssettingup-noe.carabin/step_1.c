/*
** EPITECH PROJECT, 2023
** ncarabin
** File description:
** step_1.c
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

int fs_open_file(char const *filepath )
{
    int open_test = open(filepath, O_RDONLY);

    if (open_test == (-1)) {
        my_putstr("FAILURE\n");
    } else {
        my_putstr("SUCCES\n");
    }
    close(open_test);
}
