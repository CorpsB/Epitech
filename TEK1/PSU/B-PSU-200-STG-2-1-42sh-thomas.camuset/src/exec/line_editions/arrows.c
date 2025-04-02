/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** arrows
*/

#include "../../../include/shell.h"

static void print_line(storage_bag_t *storage)
{
    char *cmd = NULL;

    cmd = get_history_by_id(storage->history, storage->prompt.actual_id);
    clear_actual_command(storage);
    my_putstr(cmd, 1);
    free(storage->prompt.command);
    storage->prompt.command = my_strdup(cmd);
}

static void left_arrow(storage_bag_t *storage)
{
    if (storage->prompt.cursor_offset > 0 &&
    my_strlen(storage->prompt.command) != 0){
        storage->prompt.cursor_offset--;
        my_putstr("\033[D", 1);
    }
}

static void right_arrow(storage_bag_t *storage)
{
    if (storage->prompt.cursor_offset < my_strlen(storage->prompt.command)
        && my_strlen(storage->prompt.command) != 0){
        storage->prompt.cursor_offset++;
        my_putstr("\033[C", 1);
    }
}

static void up_arrow(storage_bag_t *storage)
{
    if (storage->prompt.actual_id > 1 &&
    storage->prompt.actual_id <= storage->prompt.max_id){
        storage->prompt.actual_id--;
        print_line(storage);
        storage->prompt.cursor_offset = my_strlen(storage->prompt.command);
        return;
    }
    if (storage->prompt.actual_id == 0){
        storage->prompt.actual_id = storage->prompt.max_id;
        print_line(storage);
        storage->prompt.cursor_offset = my_strlen(storage->prompt.command);
    }
}

static void down_arrow(storage_bag_t *storage)
{
    if (storage->prompt.actual_id > 0 &&
    storage->prompt.actual_id < storage->prompt.max_id){
        storage->prompt.actual_id++;
        print_line(storage);
        storage->prompt.cursor_offset = my_strlen(storage->prompt.command);
        return;
    }
    if (storage->prompt.actual_id == storage->prompt.max_id){
        storage->prompt.actual_id = 0;
        print_line(storage);
        storage->prompt.cursor_offset = my_strlen(storage->prompt.command);
    }
}

static void arrow_keys_next(storage_bag_t *storage)
{
    int key;

    key = getchar();
    if (key == 'A')
        up_arrow(storage);
    if (key == 'B')
        down_arrow(storage);
    if (key == 'C')
        right_arrow(storage);
    if (key == 'D')
        left_arrow(storage);
}

void arrow_keys(storage_bag_t *storage)
{
    int key;

    key = getchar();
    if (key == '[')
        arrow_keys_next(storage);
}
