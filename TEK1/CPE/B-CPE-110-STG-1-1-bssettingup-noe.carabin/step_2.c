/*
** EPITECH PROJECT, 2023
** ncarabin
** File description:
** step_2.c
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

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int b = read(fd, buffer, size);

    if (b == (-1))
        my_putstr("read failed\n");
    if (b == 0)
        my_putstr("read has nothing more to read")
    if (b < size)
        my_putstr("read didn’t complete the entire buffer\n")
    if (b == size)
        my_putstr("read completed the entire buffer\n");
    if (b > size) {
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}
