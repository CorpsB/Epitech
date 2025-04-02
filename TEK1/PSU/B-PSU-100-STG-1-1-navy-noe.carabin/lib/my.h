/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** my.h
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
int flag_c(int c);
int flag_e(double nb, int i);
int flag_g(double nb);
int flag_g_maj(double nb);
int flag_xmaj(int nb);
int flag_x(int nb);
int flag_n(char *str);
int flag_p(long a);
int flag_s(char *c);
int flag_d(int nbr);
int flag_f(double nb);
int flag_o(int nbr);
int flag_u(unsigned int nb);
int flag_pourc(void);

#endif /*MY*/
