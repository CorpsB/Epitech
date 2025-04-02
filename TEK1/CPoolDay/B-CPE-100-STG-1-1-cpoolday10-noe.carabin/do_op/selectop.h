/*
** EPITECH PROJECT, 2023
** DO OP
** File description:
** Select operation
*/

#ifndef MY_DO_OP
    #define MY_DO_OP

    const struct operator OPERATORS_FUNCS[] = {
    {"+", &my_add},
    {"-", &my_sub},
    {"/", &my_div},
    {"*", &my_mul},
    {"%", &my_mod}, };

int my_add(int value1, int value2, int *error);
int my_sub(int value1, int value2, int *error);
int my_mul(int value1, int value2, int *error);
int my_div(int value1, int value2, int *error);
int my_mod(int value1, int value2, int *error);

struct operator {
    char *symbol;
    int (*func)(int value1, int value2, int *error);
};

#endif MY_DO_O
