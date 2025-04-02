/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-my_radar-thibaut.louis
** File description:
** Header file for libmy
*/

#ifndef MY
    #define MY

    #include <stdarg.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <stdio.h>

//Strutures du navy

typedef struct table {
    char **player_position;
    char **enemy_pos;
    bool is_game_finish;
    int pid;
    bool sig2;
    int sig1;
} table_t;

typedef struct sig {
    int sig1;
    int sig2;
    int pid;
} sig_2;

//Fonction propres au NAVY

char **crate_table(void);
void display(table_t *table);
void help(void);
int file_content_checker(char *);
void player_one_connection(table_t *table);
int player_two_connection(char *src, table_t *table);
int get_nbr(char *str);
bool is_win(char **table);
int receive_pos(void);
void send_pos(int nrb, int pid);
int attack(table_t *table);
int istouch(table_t *table);
int attack_result(table_t *table, int nbr);
int finish_game(table_t *table, int nbr);
void sig2_f(int nbr);
void sig1_f(int nbr);
int get_info(char *filepath, int size, table_t *table);
int file_content_checker(char *filepath);
int send_pid(int nbr);
int get_pid(int nbr);

//Include de la lib
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_strcat(char *dest, char const *src);
int my_strlen(const char *str);
void aff_point(const char *name);
void lsflag_l(const char *chemin);
int my_strcmp(const char *s1, const char *s2);
void lsflag_rmaj(const char *chemin);
char *my_strdup(const char *str);
int my_printf(const char *format, ...);
int my_compute_power_it(int nb, int p);
int my_str_to_int(char *str);
int my_min(int a, int b, int c);
int my_atoi(const char *str);
int my_isdigit(int c);
int compt_tabl(char **args);
int diff(char *arg);

#endif /*MY*/
