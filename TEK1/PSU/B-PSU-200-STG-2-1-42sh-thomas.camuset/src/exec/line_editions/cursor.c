/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** cursor
*/

#include "../../../include/shell.h"

void clear_actual_command(storage_bag_t *storage)
{
    free(storage->prompt.command);
    storage->prompt.command = my_strdup("");
    for (int i = 0; i < storage->prompt.cursor_offset; i++)
        my_putstr("\033[D", 1);
    my_putstr("\033[0K", 1);
}

void clear_line(storage_bag_t *storage)
{
    int length = my_strlen(storage->prompt.command);

    for (int i = 0; i < (length - storage->prompt.cursor_offset); i++)
        my_putstr("\033[C", 1);
    for (int i = 0; i < length; i++){
        my_putstr("\b \b", 1);
        if (i + 1 == length)
            my_putstr("\b", 1);
    }
}

void clear_line_backspace(storage_bag_t *storage)
{
    my_putstr("\033[0K", 1);
    my_putstr("\b \b", 1);
}

void replace_cursor(storage_bag_t *storage)
{
    for (int i = 0; i < (my_strlen(storage->prompt.command) -
        storage->prompt.cursor_offset) - 1; i++)
        my_putstr("\033[D", 1);
}

void replace_cursor_backspace(storage_bag_t *storage)
{
    for (int i = storage->prompt.cursor_offset - 1;
        storage->prompt.command[i] != '\0'; i++)
        my_putchar(storage->prompt.command[i], 1);
    for (int i = 0; i < (my_strlen(storage->prompt.command) -
        storage->prompt.cursor_offset) + 1; i++)
        my_putstr("\033[D", 1);
}
