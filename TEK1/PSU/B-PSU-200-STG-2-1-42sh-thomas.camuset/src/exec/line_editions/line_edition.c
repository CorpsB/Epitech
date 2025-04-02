/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** line_edition
*/

#include "../../../include/shell.h"

void print_normal_key(storage_bag_t *storage, int key)
{
    if (key < 32)
        return;
    my_putchar(key, 1);
    storage->prompt.command = s_insert(storage->prompt.command,
    key, storage->prompt.cursor_offset);
    clear_line(storage);
    my_putstr(storage->prompt.command, 1);
    replace_cursor(storage);
    storage->prompt.cursor_offset += 1;
}

void backspace_key(storage_bag_t *storage)
{
    if (my_strlen(storage->prompt.command) > 0 &&
    storage->prompt.cursor_offset != 0){
        storage->prompt.command = s_remove_index(storage->prompt.command,
        storage->prompt.cursor_offset - 1);
        clear_line_backspace(storage);
        replace_cursor_backspace(storage);
        storage->prompt.cursor_offset--;
    } else
        my_putchar('\a', 1);
}

static void advanced_key_selector(storage_bag_t *storage)
{
    switch (storage->prompt.key){
        case '\033':
            return arrow_keys(storage);
        case '\t':
            return exec_tabs(storage);
        default:
            return print_normal_key(storage, storage->prompt.key);
    }
}

static void key_selector(storage_bag_t *storage)
{
    switch (storage->prompt.key){
        case 1:
            return move_cursor_far_left(storage);
        case 4:
            return is_end_of_file(storage);
        case 8:
            return backspace_key(storage);
        case 11:
            return delete_line_after_cursor(storage);
        case 23:
            return delete_line_before_cursor(storage);
        case 25:
            return paste_clipboard(storage);
        case 127:
            return backspace_key(storage);
        default:
            return advanced_key_selector(storage);
    }
}

void line_edition(storage_bag_t *storage)
{
    char w_dir[1000];

    getcwd(w_dir, 1000);
    print_prompt_exit_code(storage, w_dir);
    storage->prompt.command = my_strdup("");
    while (1){
        if (storage->is_exit != 0)
            break;
        storage->prompt.key = getchar();
        storage->prompt.max_id = storage->history->id;
        if (storage->prompt.key == 10){
            my_putchar('\n', 1);
            storage->prompt.cursor_offset = 0;
            break;
        }
        key_selector(storage);
    }
}
