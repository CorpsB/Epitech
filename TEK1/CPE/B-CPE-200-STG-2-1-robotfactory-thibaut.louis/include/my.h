/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-navy-noe.carabin
** File description:
** my.h
*/

#ifndef MY
    #define MY

    #include "../B-CPE-200_op/op.h"
    #include <stdarg.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <string.h>

    #define MAX_ARGS_NUMBER 3
    #define HEADER_SIZE 2192

int check_file(char *str, int);
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(const char *str);
void aff_point(const char *name);
void lsflag_l(const char *chemin);
int my_strcmp(const char *s1, const char *s2);
void lsflag_rmaj(const char *chemin);
char *my_strdup(const char *str);  //copie et malloc une liste (char *)
int my_printf(const char *format, ...);
int my_compute_power_it(int nb, int p); // met une puissance
int my_str_to_int(char *str);
int my_min(int a, int b, int c);
int my_getnbr(const char *str);
int my_isdigit(int c);
int compt_tabl(char **args); //compte le nbr d'élément dans un tabl
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
char *my_revstr(char *str); // reverse un char *
char **my_str_to_word_array(char const *str); // met un str dans tableau
char *my_str_cat(char *str1, char *str2, char sep);
// concatène deux char * en les malloc
int tabl_size(char **result); //taile d'un tableau
char **tabl_copy(char **tabl); // copy tableau + malloc
void aff_tabl(char **result); //aff tableau
void free_tabl(char **result); //free tableau
char *my_strlowcase(char *str); //met en minuscule un char *
char *my_strupcas(char *str); // maj un char *
int int_size(long long int nbr); // taille d'un nbr
int my_puterror(char *str);
int my_str_isnum(char const *str);
char *my_substr(char *str1, int final, int begin);
char **my_str_to_word_array_upgrade(char *str, char sep1, char sep2);
char *clean_str(char *str, char sep1, char sep2);
int skip(char *str, int i, char sep1, char sep2);
char *my_str_cat2(char *str1, char *str2);
int my_strncmp(const char *str1, const char *str2, int n);
void clean_array(char ***tabl);
void print_help(void);
char *my_strcpy(char *dest, char const *src);
int get_opcode(const char *instr);
void parse_name_line(char *line, header_t *header);
void comment_len_fct(size_t comment_len, header_t *header);
void parse_comment_line(char *line, header_t *header);
void parse_header(FILE *file, header_t *header);
void write_header(FILE *output, header_t *header);

#endif /*MY*/
