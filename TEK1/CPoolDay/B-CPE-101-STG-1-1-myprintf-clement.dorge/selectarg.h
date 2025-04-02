/*
** EPITECH PROJECT, 2023
** DO OP
** File description:
** Select operation
*/

#ifndef PRINT_F
    #define PRINT_F

    #include <stdarg.h>

int mini_c(va_list a, char *, int, int);
int mini_d(va_list a, char *, int, int);
int mini_i(va_list a, char *, int, int);
int mini_o(va_list a, char *, int, int);
int mini_s(va_list a, char *, int, int);
int mini_u(va_list a, char *, int, int);
int mini_e(va_list a, char *, int, int);
int mini_ee(va_list a, char *, int, int);
int mini_f(va_list a, char *, int, int);
int mini_x(va_list a, char *, int, int);
int mini_xup(va_list a, char *, int, int);
int mini_b(va_list a, char *, int, int);
int mini_p(va_list a, char *, int, int);
int mini_g(va_list a, char *, int, int);
int mini_gg(va_list a, char *, int, int);

struct operator {
    char *symbol;
    int (*func)(va_list a, char *, int, int);
};

struct get_form {
    int ok;
    int width;
    int precision;
    char *shape;
    char *temp;
    int c;
    char f;
};

const struct operator OPERATORS_FUNCS[] = {
    {"c000\0", &mini_c},
    {"d000\0", &mini_d},
    {"i000\0", &mini_i},
    {"o000\0", &mini_o},
    {"s000\0", &mini_s},
    {"u000\0", &mini_u},
    {"e000\0", &mini_e},
    {"E000\0", &mini_ee},
    {"f000\0", &mini_f},
    {"F000\0", &mini_f},
    {"x000\0", &mini_x},
    {"X000\0", &mini_xup},
    {"b000\0", &mini_b},
    {"p000\0", &mini_p},
    {"g000\0", &mini_g},
    {"G000\0", &mini_gg},
    {"\0000\0", }
};

#endif /*PRINT_F*/
