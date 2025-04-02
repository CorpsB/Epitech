/*
** EPITECH PROJECT, 2023
** new_folder
** File description:
** my.h
*/

#ifndef MY
    #define MY

    //INCLUDE:

    //Librarie booléen
    #include <stdbool.h>
    //Lib printf
    #include <stdio.h>
    //Lib de valeur NULL
    #include <stddef.h>
    //Malloc, free, exit, rand
    #include <stdlib.h>
    //Librarie stat
    #include <sys/stat.h>
    //Lib open close
    #include <fcntl.h>
    //Opendir, close, readir
    #include <dirent.h>
    //Macro permission
    #include <sys/stat.h>
    //Librarie WRITE (putchar et put_str)
    #include <unistd.h>
    //Transformer ID auteur en str
    #include <pwd.h>
    //Transformer ID groupe en str
    #include <grp.h>
    //Formatage du temps avec ctime
    #include <time.h>
    #include <sys/wait.h>
    #include <signal.h>
    //Erno
    #include <errno.h>

//Structures listes chainés :
typedef struct linked_list {
    char *name;
    char *value;
    int id;
    struct linked_list *next;
} linked_t;

typedef struct linked_path {
    char *path;
    struct linked_path *next;
} path_t;

//Structure :
typedef struct global_infos {
    int error;
    char **env;
    linked_t *env_l;
} infos_t;

typedef struct redi_s {
    bool exit;
    bool big_exit;
    bool little_exit;
    bool enter;
    bool big_enter;
    bool little_enter;
    char *ex_filepath;
    char *en_filepath;
} red_t;

typedef struct pipe_s {
    int pipe;
    int fd[2];
    int old_fd[2];
    int error;
    red_t *red;
} pipe_t;


//Fonctions du minbishell2 :
int which_operator(char *str, infos_t *list);
void search_execut_env(pipe_t *pipe, int i, int size, char **table);
//Pipe :
int execute_with_pipe(char *clean_str, infos_t *infos);
bool pipe_error(char **table);
//Semilicon
int execute_semilicon(char *str, infos_t *infos);
//Redirection
bool redirection(pipe_t *pipe, int i, int size, char **table);
void complete_redirection(pipe_t *pipe, char **table, red_t *red);
//Focntions searcher
bool char_searcher(char *str, char search);
bool search_enter_redirection(char **table);
bool search_exit_redirection(char **table);

//Getnbr
int get_nbr(char *str);

//Focntion du minishell1 :
int bad_architecture(int exit, char **command);
int which_commands(char *str, infos_t *infos, pipe_t *pipe_infos);
void free_infos(linked_t **list);
void free_path(path_t **list);
void change_env(char ***mem_env, linked_t *list, char sep);
int str_len_to(char *str, int index, char separator);
void free_table(char **table);
void re_build_env(char **env, linked_t **l_env);
char *format_str(char *str, bool need);
void change_env(char ***mem_env, linked_t *list, char sep);
int message(int exit_code, int exit_in, int nbr, ...);
int my_error(char const *str);
int change_directory(linked_t **env, char **infos);
int table_len(char **table);
int show_env(linked_t *env_l, char **command);
int set_environement(char **infos, linked_t **list);
int remove_env(linked_t **list, char **name);
char *write_withoutlast(char *str, bool need);
bool is_a_dir(char *filepath);
bool is_exec_func(char **command);
int segv_func(int status);

//Focntions des listes chainés :
int del_in_list(linked_t **list, int id);
int my_put_in_list(linked_t **list, char *name, char *value);
int my_list_size(linked_t *begin);
void my_show_list(linked_t *list);
void my_show_revlist(linked_t *tmp);
int sort_name(linked_t **something);
int search_from_list(linked_t *list, char *name);

//Fonctions de la lib
char *my_substr(char *str, int start, int end);
char **str_to_array(char *map, char sep);
char *my_strdup(char *src);
char *my_strstr(char *src, char *se, char separator);
int my_is_prime_test(int nb);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
void my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

#endif /*MY*/
