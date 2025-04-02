/*
** EPITECH PROJECT, 2024
** ADVANCED CONTROLS
** File description:
** Yes.
*/

#include "../../../include/shell.h"

static void withdraw_ignoreeof(storage_bag_t *storage, int nb)
{
    char w_dir[1000];

    ++storage->prompt.eof_count;
    my_putstr("^D\nUse \"exit\" to leave 42sh.\n", 1);
    storage->prompt.cursor_offset = 0;
    getcwd(w_dir, 1000);
    print_prompt_exit_code(storage, w_dir);
    free(storage->prompt.command);
    storage->prompt.command = my_strdup("");
}

void is_end_of_file(storage_bag_t *storage)
{
    char *ignoreeof = get_variable_set(storage->set, "ignoreeof");
    bool execute = false;
    int nb;

    if (ignoreeof == NULL){
        storage->prompt.eof_count = 1;
        storage->is_exit = 1;
        return;
    }
    nb = n_convert_s(ignoreeof);
    if (my_strlen(ignoreeof) == n_size(nb))
        execute = true;
    if (!execute)
        my_putstr("Use \"exit\" to leave 42sh.\n", 1);
    else if (storage->prompt.eof_count == nb)
        storage->is_exit = 1;
    else
        withdraw_ignoreeof(storage, nb);
}

void move_cursor_far_left(storage_bag_t *storage)
{
    while (storage->prompt.cursor_offset > 0 &&
    my_strlen(storage->prompt.command) != 0){
        storage->prompt.cursor_offset--;
        my_putstr("\033[D", 1);
    }
}

void delete_line_after_cursor(storage_bag_t *storage)
{
    int st_pos = storage->prompt.cursor_offset;
    char *new_cmd;
    int cmd_size = my_strlen(storage->prompt.command);

    while (storage->prompt.cursor_offset < cmd_size && cmd_size != 0){
        storage->prompt.cursor_offset++;
        my_putstr("\033[C", 1);
    }
    if (storage->prompt.clipboard != NULL)
        free(storage->prompt.clipboard);
    storage->prompt.clipboard = (st_pos < cmd_size) ?
    my_substr(storage->prompt.command, st_pos, cmd_size) : my_strdup("");
    for (; storage->prompt.cursor_offset > st_pos;)
        backspace_key(storage);
}

void delete_line_before_cursor(storage_bag_t *storage)
{
    int ed_pos = storage->prompt.cursor_offset;
    char *new_cmd;
    int cmd_size = my_strlen(storage->prompt.command);

    if (storage->prompt.clipboard != NULL)
        free(storage->prompt.clipboard);
    storage->prompt.clipboard = (0 < ed_pos) ?
    my_substr(storage->prompt.command, 0, ed_pos) : my_strdup("");
    for (; storage->prompt.cursor_offset > 0;)
        backspace_key(storage);
}

void paste_clipboard(storage_bag_t *storage)
{
    int size;

    if (storage->prompt.clipboard == NULL ||
    storage->prompt.clipboard[0] == '\0')
        return;
    size = my_strlen(storage->prompt.clipboard);
    for (int i = 0; i < size; ++i)
        print_normal_key(storage, storage->prompt.clipboard[i]);
}
