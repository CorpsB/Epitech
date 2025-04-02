/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** List of functions avaliable in 42sh.
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <termios.h>
    #include <stdbool.h>
    #include <time.h>

typedef struct history {
    char *temps;
    char *cmd_line;
    int id;
    struct history *next;
} history_t;

typedef struct file {
    char *data;
    int is_dir;
    struct file *next;
} file_t;

typedef struct var_list {
    char *name;
    char *value;
    struct var_list *next;
} var_list_t;

typedef struct line_edition {
    char *command;
    char *clipboard;
    int key;
    int actual_id;
    int max_id;
    int cursor_offset;
    int eof_count;
} line_edition_t;

typedef enum token_type {
    ERROR_TOKEN,
    COMMAND_TOKEN,
    COMMAND_ARG_TOKEN,
    PIPE_TOKEN,
    CHEVRON_LEFT_TOKEN,
    CHEVRON_RIGHT_TOKEN,
    SEMICOLON_TOKEN,
    AMPERSAND_TOKEN,
    PARENTHESE_START_TOKEN,
    PARENTHESE_END_TOKEN,
    EXTERNAL_PARENTHESE_TOKEN
} token_type_t;

typedef struct cmd_data {
    int TOKEN;
    char *value;
    struct cmd_data *next;
} cmd_data_t;

typedef struct pipe_data {
    char *chev_left;
    char *chev_right;
    char **build_cmd;
    int mode;
    bool instance;
    cmd_data_t *raw_cmd;
    struct pipe_data *next;
} pipe_data_t;

typedef struct file_data {
    char *directory;
    char *f_name;
} file_data_t;

typedef struct storage_bag {
    char **env;
    char **pathlist;
    char *username;
    char hostname[1000];
    int is_exit;
    int exit_code;
    char path_to_42sh[1000];
    bool allow_history;
    bool is_tty;
    var_list_t *alias;
    var_list_t *set;
    history_t *history;
    line_edition_t prompt;
} storage_bag_t;

typedef struct vector3i {
    int x;
    int y;
    int z;
} vector3i_t;

#endif
