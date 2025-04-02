/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** List of functions avaliable in 42sh.
*/

#ifndef MY_SHELL
    #define MY_SHELL
    #define ERR 1
    // ; moved out because of coding style
    #define ALLOWED_TOKENS "<>|&()"
    #define SKIP_CHARS " \t"
    #define MAX_TIME_LENGTH 20

    #include "base/fundation.h"
    #include <pwd.h>
    #include "sys/types.h"
    #include <termios.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include "struct.h"
    #include <ctype.h>

static struct termios old_termios;

// fork lib functions
void my_lim_putstr(char const *str, int i);
int l_add_history(history_t **list, char *line, char *temps);
void l_free_history(history_t **list);
void l_display_history(history_t *list);
void l_free_var(var_list_t **list);
void l_add_var(var_list_t **list, char *name, char *value);
void l_reverse_var(var_list_t **list);
int l_size_var(var_list_t *list);
void l_display_var(var_list_t *list);
var_list_t *l_sort(var_list_t *list);
char *s_convert_a(char **array, int i);
char **get_tab_by_arg(char *str, char *sep);
void l_reverse_history(history_t **list);
void l_replace_cmd(cmd_data_t **list, cmd_data_t *tmp,
    char **replace_data);
char *exec_42sh(storage_bag_t *storage, char *data, char **tab);
char *my_origin_strtok(char *str, char *clean_list);
void l_remove_cmd(cmd_data_t **list, cmd_data_t *to_delete);

// init functions
void init_42sh(storage_bag_t *storage, char **env);
void clean_42sh(storage_bag_t *storage);
char *get_actual_time(void);

// parsing functions
int count_backticks(char *str);
int count_guillemet(char *str);
int is_alpha_name(char *str);
int reveal_variables(storage_bag_t *storage, cmd_data_t *line);
char *get_sys_variable(storage_bag_t *storage, char *key);
char *get_variable_set(var_list_t *list, char *key);
void replace_backticks(storage_bag_t *storage, cmd_data_t **line);
int count_paranthesis(char *str);
int check_parenthese(storage_bag_t *storage, cmd_data_t **data, char *str);
char *get_raw_cmd_from_build(int *i_max, cmd_data_t *data);

// temporary build analysis function
void draw_cmd(cmd_data_t *data);

// operators call functions
int parse_or_operator(storage_bag_t *storage, cmd_data_t *line);
int parse_and_operator(storage_bag_t *storage, cmd_data_t *line);

// prompt
void print_prompt_exit_code(storage_bag_t *storage, char w_dir[1000]);
int run_prompt_tty(storage_bag_t *storage);
int open_rc(storage_bag_t *storage);

// termios
void disable_raw_mode(void);
void enable_raw_mode(void);

// line editions
void line_edition(storage_bag_t *storage);
void arrow_keys(storage_bag_t *storage);
char *get_history_by_id(history_t *list, int id);
void exec_tabs(storage_bag_t *storage);
void is_end_of_file(storage_bag_t *storage);
void delete_line_after_cursor(storage_bag_t *storage);
void delete_line_before_cursor(storage_bag_t *storage);
void backspace_key(storage_bag_t *storage);
void print_normal_key(storage_bag_t *storage, int key);
void paste_clipboard(storage_bag_t *storage);
file_data_t get_file_data(char *command, int offset);
int get_chevron_data(cmd_data_t **tmp, char **stock, int type);

// folder_utils
void fill_files(file_t **files, char *folder, char *f_name);
void display_files(file_t *files);
int count_files_in_folder(file_t *files);
void add_file(file_t **files, int type, char *name);
void free_files(file_t **files);
int is_file_in_files(file_t *files, char *data);

// cursor
void clear_actual_command(storage_bag_t *storage);
void clear_line(storage_bag_t *storage);
void clear_line_backspace(storage_bag_t *storage);
void replace_cursor(storage_bag_t *storage);
void replace_cursor_backspace(storage_bag_t *storage);
void move_cursor_far_left(storage_bag_t *storage);

// get user env
void get_userdata(storage_bag_t *storage);

// history
void history(storage_bag_t *storage, cmd_data_t *data);
int disp_history(storage_bag_t *storage, char **cmd);
void load_history_line(history_t **history, char *line);
void load_history(history_t **history);
void save_history(history_t **history);
int excl_history(storage_bag_t *storage, char **cmd, bool is_print);
int redirect_history(storage_bag_t *storage, cmd_data_t *data);
char *find_hist(storage_bag_t *storage, char *cmd);

// special variables
void exec_precmd(storage_bag_t *storage);
void exec_cwdcmd(storage_bag_t *storage);

// aliases functions
var_list_t *get_alias_ptr(var_list_t *list, char *search);
int redirect_aliases(storage_bag_t *storage, cmd_data_t **data);
char *get_alias_redirect(storage_bag_t *storage, char *cmd);
int redirect_alias_test_loop(storage_bag_t *storage, char *cmd);
int alias(storage_bag_t *storage, char **cmd);
int unalias(storage_bag_t *storage, char **cmd);

// set local value
int unset(storage_bag_t *storage, char **cmd);
int set(storage_bag_t *storage, char **cmd);
void l_remove_var(var_list_t **list, var_list_t *to_delete);

// parentheses
int check_parenthese(storage_bag_t *storage, cmd_data_t **data, char *line);
int extract_parentheses(cmd_data_t **data, storage_bag_t *storage);
int exec_42sh_p_pipe(storage_bag_t *storage, char **tab, char *data);
void parenthese_builder(pipe_data_t *data, cmd_data_t *line);

#endif
