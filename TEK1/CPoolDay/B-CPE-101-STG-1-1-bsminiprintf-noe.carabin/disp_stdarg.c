/*
** EPITECH PROJECT, 2023
**  
** File description:
**  
*/

#include <stdio.h>
#include <stdarg.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int a)
{
    int b = a;
    int cpt = 0;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (a > 9) {
        my_put_nbr(a / 10);
    }
    my_putchar(a % 10 + 48);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i = i + 1) {
            my_putchar(str[i]);
    }
}

int disp_stdarg(char *s, ...)
{
    va_list a_lot_things;

    va_start(a_lot_things, s);
    for (int cpt = 0; s[cpt] != NULL; cpt++) {
        switch (s[cpt]) {
        case 'c':
            my_putchar(va_arg(a_lot_things, int));
        case 'i':
            my_put_nbr(va_arg(a_lot_things, int));
        case 's':
            my_putstr(va_arg(a_lot_things, char*));
        }
    }
    va_end(a_lot_things);
}

int main(void)
{
    char *s = "cissic";
    disp_stdarg(s, 'D', 34, "YOUPI", "YOUPI", 34, 'D');
}
