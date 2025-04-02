/*
** EPITECH PROJECT, 2023
** MINI_PRINTF (CORE)
** File description:
** The main part of the mini_printf function.
*/

#include "../../../include/my.h"
static void print_text(va_list list)
{
    my_putstr(va_arg(list, char *), 1);
}

static void print_num(va_list list)
{
    my_putnbr(va_arg(list, int), 1);
}

static void print_char(va_list list)
{
    my_putchar(va_arg(list, int), 1);
}

static void print_pourcent(va_list list)
{
    my_putchar('%', 1);
}

static int is_equal(va_list list, char c, int *wake_up)
{
    void (*Operations[6])(va_list) =
    {print_text, print_char, print_num, print_num,
    print_pourcent};
    char operateurs[] = "scdi%";

    for (int j = 0; operateurs[j] != '\0'; ++j){
        if (operateurs[j] == c){
            Operations[j](list);
            *wake_up = 0;
        }
    }
}

static void verif_carac(char c, va_list list, int *wake_up)
{
    if (*wake_up){
        is_equal(list, c, wake_up);
    } else if (c == '%'){
        *wake_up = 1;
    } else {
        my_putchar(c, 1);
    }
}

void my_printf(const char *str, ...)
{
    va_list list;
    int wake_up = 0;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; ++i){
        verif_carac(str[i], list, &wake_up);
    }
    va_end(list);
}
