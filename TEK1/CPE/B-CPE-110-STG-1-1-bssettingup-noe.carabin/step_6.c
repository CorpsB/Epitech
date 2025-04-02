/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-bssettingup-noe.carabin
** File description:
** step_6.c
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

void fs_get_number_from_first_line(char const *filepath)
{
    char buffer;
    int size = 1;
    int a = open(filepath, O_RDONLY);
    int b = read(filepath, buffer, size);

    if (b < 0 || a == (-1) || ) {
        return (-1);
    }
    while (buffer != '\n') {
        if (buffer < 48 || buffer > 57) {
            return (-1);
        }
        read(filepath, buffer, size);
        my_putchar(buffer);
    }
    close(filepath);
    return 0;
}
