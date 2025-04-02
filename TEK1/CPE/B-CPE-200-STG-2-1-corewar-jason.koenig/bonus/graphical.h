/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** graphical.h
*/

#ifndef GRAPHICAL
    #define GRAPHICAL
    #define LCHAR 250

    #include <ncurses.h>

// graphical functions
void print_title(int size, WINDOW *win, char ***title);
char **letter_c(void);
char **letter_o(void);
char **letter_r(void);
char **letter_e(void);
char **letter_w(void);
char **letter_a(void);
char ***init_title(void);
void print_arena(WINDOW *win, corewar_t *vm);
void print_champions(corewar_t *vm, WINDOW *win);
void print_cycle(int before, WINDOW *win, int cycle);
void graphical(corewar_t *vm, int cycle, WINDOW *win, char ***title);

#endif
