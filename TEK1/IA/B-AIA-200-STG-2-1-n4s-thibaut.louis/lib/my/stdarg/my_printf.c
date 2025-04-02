/*
** EPITECH PROJECT, 2023
** MINI_PRINTF (CORE)
** File description:
** The main part of the mini_printf function.
*/

#include "../../../include/my.h"
static void print_text(va_list list, int port)
{
    my_putstr(va_arg(list, char *), port);
}

static void print_num(va_list list, int port)
{
    my_putnbr(va_arg(list, int), port);
}

static void print_char(va_list list, int port)
{
    my_putchar(va_arg(list, int), port);
}

static void print_pourcent(va_list list, int port)
{
    my_putchar('%', port);
}

static int is_equal(va_list list, char c, int *wake_up, int port)
{
    void (*Operations[6])(va_list, int) =
    {print_text, print_char, print_num, print_num,
    print_pourcent};
    char operateurs[] = "scdi%";

    for (int j = 0; operateurs[j] != '\0'; ++j){
        if (operateurs[j] == c){
            Operations[j](list, port);
            *wake_up = 0;
        }
    }
}

static void verif_carac(char c, va_list list, int *wake_up, int port)
{
    if (*wake_up){
        is_equal(list, c, wake_up, port);
    } else if (c == '%'){
        *wake_up = 1;
    } else {
        my_putchar(c, port);
    }
}

void my_printf(int port, const char *str, ...)
{
    va_list list;
    int wake_up = 0;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; ++i){
        verif_carac(str[i], list, &wake_up, port);
    }
    va_end(list);
}
