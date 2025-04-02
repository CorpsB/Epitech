/*
** EPITECH PROJECT, 2023
** Mini printF
** File description:
** Like printF but mini
*/

#include <stdarg.h>

int grand_switch(char *format, va_list parametersInfos, int cpt)
{
    switch (format[cpt + 1]) {
    case 'd':
        mini_d(va_arg(parametersInfos, int));
        break;
    case 'i' :
        mini_i(va_arg(parametersInfos, int));
        break;
    case 's':
        mini_s(va_arg(parametersInfos, char *));
        break;
    case 'c':
        mini_c(va_arg(parametersInfos, int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        write(2, 84, 2);
        break;
    }
}

int mini_printf(char *format, ...)
{
    va_list parametersInfos;

    va_start(parametersInfos, format);
    for (int cpt = 0; format[cpt] != '\0';) {
        if (format[cpt] == '%') {
            grand_switch(format, parametersInfos, cpt);
            cpt = cpt + 2;
        } else {
            my_putchar(format[cpt]);
            cpt++;
        }
    }
    va_end(parametersInfos);
    return 0;
}
