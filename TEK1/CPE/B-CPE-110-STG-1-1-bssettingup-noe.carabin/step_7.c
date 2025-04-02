/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-bssettingup-noe.carabin
** File description:
** step_7.c
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

void array_1d_print_chars(char const *arr)
{
    char buffer;
    int size = 1;
    int a = open(arr, O_RDONLY);
    int b = read(arr, buffer, size);

    if (b < 0) {
        return 84;
    }
    for (b != 0) {
        my_putchar(buffer);
        for (;buffer != '\n';) {
            read(arr, buffer, size)
        }
        read(arr, buffer, size);
    }
    close(arr);
    return 0;
}
