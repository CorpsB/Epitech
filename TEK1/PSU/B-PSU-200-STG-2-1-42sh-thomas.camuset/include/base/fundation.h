/*
** EPITECH PROJECT, 2023
** 42SH
** File description:
** List of functions avaliable in 42sh.
*/

#ifndef FONDATION_H
    #define FONDATION_H

    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <errno.h>
    #include "my.h"
    #include "../struct.h"

// -----------------------------
// fork lib functions
// -----------------------------

int s_count(char *str, char c1, char c2);
char **a_convert_s(char *str, char sep, char sep2);
char *s_sepmerge(char *dest, char const *src, char sep);
char *s_sependmerge(char *dest, char const *src, char sep);
char *my_strtok(char *str, char *clean_list);
char *my_getline(char *str, int *i, char sep);
char *my_readfd(int fd);
void l_cmd_add(cmd_data_t **list, void *arg, int token);
void l_cmd_free(cmd_data_t **list);
void l_cmd_reverse(cmd_data_t **list);
int s_litsearch(char const *str, char c);
void l_pipe_add(pipe_data_t **list, char *left, char *right);
void l_pipe_free(pipe_data_t **list);
void l_pipe_reverse(pipe_data_t **list);
int l_pipe_size(pipe_data_t *list);

// -----------------------------
// path functions
// -----------------------------

char *get_variable(char **env, char *arg);
int get_pathline(char **env, char *arg);
char **get_pathlist(char **env);

// -----------------------------
// return functions
// -----------------------------

int msg(int exit_code, int port, int nb, ...);

// -----------------------------
// program main functions
// -----------------------------

int run_prompt(storage_bag_t *storage);
int run_subcommand(storage_bag_t *storage, char **cmd);
int run_command(storage_bag_t *storage, char *str);
int run_pipe_command(storage_bag_t *storage, pipe_data_t *data);
int exec_pipe(storage_bag_t *storage, char **cmd_line, char *data);
int exec_pipeline(storage_bag_t *storage, pipe_data_t *data, int size);
int exec_chevron(storage_bag_t *storage, pipe_data_t *data);

// -----------------------------
// built-in functions
// -----------------------------

int display_env(storage_bag_t *storage, char **cmd);
int exit_prompt(storage_bag_t *storage, char **cmd);
int change_directory(storage_bag_t *storage, char **data);
int change_wd(storage_bag_t *storage, char *path);
int change_path(storage_bag_t *storage, char *path);
int exec_unbuiltin(storage_bag_t *storage, char **data);
char *path_retriever(char *name, char **pathlist);
int exec_path(char **env, char **data, char *bin_path);
int set_env(storage_bag_t *storage, char **data);
int choice_set_method(storage_bag_t *storage, char *arg, char *value);
int edit_env(storage_bag_t *storage, char *arg, char *value, int pathline);
int add_env(storage_bag_t *storage, char *arg, char *value);
int unset_env(storage_bag_t *storage, char **data);
static int remove_env(storage_bag_t *storage, char *arg);
int exit_signal(int status);

// -----------------------------
// detection functions
// -----------------------------

int is_subcommand(char **cmd);

// -----------------------------
// parsing functions
// -----------------------------

int parse_data(cmd_data_t **data, char *line, storage_bag_t *storage);
int parse_semicolon(storage_bag_t *storage, cmd_data_t *line);
int parse_pipe(storage_bag_t *storage, cmd_data_t *line);
int parse_chevron(pipe_data_t *data);
void command_builder(pipe_data_t **data, cmd_data_t *line);
int is_parsing_error(cmd_data_t *line);

#endif
