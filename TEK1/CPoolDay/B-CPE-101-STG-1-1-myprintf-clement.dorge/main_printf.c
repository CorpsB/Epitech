/*
** EPITECH PROJECT, 2023
** printf
** File description:
** the main fonction
*/

#include <stdarg.h>
#include "selectarg.h"
#include <stddef.h>

static void parameterssetshape(char *format, int *cpt, struct get_form *st,
    char f)
{
    if (f != ' ' && f != '+' && f != '0' && f != '-' && f != '#')
        return;
    if (f == ' ') {
        *cpt += 1;
        if (st->shape[0] != '+')
            st->shape[st->c] = ' ';
        for (;format[*cpt + 1] == ' '; *cpt += 1);
        if (format[*cpt + 1] == '-' || format[*cpt - 1] == '-' ||
            format[*cpt + 1] == '0')
            st->c += 1;
        parameterssetshape(format, cpt, st, format[*cpt + 1]);
    } else {
        if (f == '#')
            st->shape[3] = '#';
        else
            st->shape[st->c] = f;
        *cpt += 1;
        st->c += 1;
        parameterssetshape(format, cpt, st, format[*cpt + 1]);
    }
}

void parametersset(char *format, int *cpt, struct get_form *st)
{
    int num;

    while (format[*cpt + 1] <= '9' && format[*cpt + 1] >= '0') {
        num = format[*cpt + 1];
        st->width = (st->width + num - 48) * 10;
        *cpt += 1;
    }
    if (st->width != NULL)
        st->width /= 10;
    if (format[*cpt + 1] == '.') {
        *cpt += 1;
        while (format[*cpt + 1] <= '9' && format[*cpt + 1] >= '0') {
            num = format[*cpt + 1];
            st->precision = (st->precision + num - 48) * 10;
            *cpt += 1;
        }
        st->precision /= 10;
    }
}

static int booltest(char f)
{
    if ((f >= 'a' && f <= 'g') || f == 'i' || f == 'n' || f == 'o' ||
        f == 'p' || f == 's' || f == 'u' || f == 'x' || f == 'A' ||
        f == 'E' || f == 'X' || f == 'F' || f == 'G')
        return 0;
    return 1;
}

static int booltestflag(char f)
{
    if ((f >= 'a' && f <= 'j') || f == 'l' || f == 'n' || f == 'o' ||
        f == 'p' || f == 's' || f == 'u' || f == 'x' || f == 't' ||
        f == 'L' || f == 'A' || f == 'E' || f == 'X' || f == 'F' || f == 'G')
        return 1;
    return 0;
}

static char *parameterssettemp(char *format, int *cpt, struct get_form *st)
{
    char f = format[*cpt + 1];
    int i = 0;
    int b = 1;
    int c = booltestflag(f);

    while (i < 4 && b == 1 && c == 1) {
        if (f != 'l' && f != 'h' && f != 'j' && f != 't' && f != 'L')
            st->temp[i] = f;
        i += 1;
        f = format[*cpt + 1 + i];
        b = booltestflag(f);
        c = booltest(f);
    }
}

static void arg_next(struct get_form *st)
{
    int i = 0;

    if (st->ok == 0) {
        my_putchar('%');
        while (st->temp[i] == 'l' || st->temp[i] == 'L' ||
        st->temp[i] == 'h' || st->temp[i] == 'j' || st->temp[i] == 't')
            i += 1;
        for (; st->temp[i] != '0'; i++)
            my_putchar(st->temp[i]);
    }
}

struct get_form formget(char *format, int *cpt)
{
    struct get_form newform;

    newform.ok = 0;
    newform.width = NULL;
    newform.precision = NULL;
    newform.shape = malloc(sizeof(char) * 4 + 1);
    newform.temp = malloc(sizeof(char) * 4 + 1);
    newform.c = 0;
    newform.f = format[*cpt + 1];
    for (int a = 0; a < 4; a++) {
        newform.shape[a] = NULL;
        newform.temp[a] = '0';
    }
    newform.shape[4] = '\0';
    newform.temp[4] = '\0';
    return newform;
}

int argument_select(char *format, va_list parametersInfos, int *cpt)
{
    struct get_form st = formget(format, cpt);
    struct get_form *ptr = &st;

    if (format[*cpt + 1] != '%' && format[*cpt + 1] != 'n') {
        parameterssetshape(format, cpt, ptr, format[*cpt + 1]);
        parametersset(format, cpt, ptr);
        parameterssettemp(format, cpt, ptr);
    }
    for (int compteur = 0; OPERATORS_FUNCS[compteur].symbol[0] != '\0';
    compteur++) {
        if (st.f != '%' && st.f != 'n' &&
        st.temp[0] == OPERATORS_FUNCS[compteur].symbol[0] &&
        st.temp[1] == OPERATORS_FUNCS[compteur].symbol[1] &&
        st.temp[2] == OPERATORS_FUNCS[compteur].symbol[2]) {
            OPERATORS_FUNCS[compteur].func(parametersInfos, st.shape,
            st.width, st.precision);
            st.ok++;
        }
    }
    arg_next(ptr);
}

int my_printf(char *format, ...)
{
    va_list parametersInfos;

    va_start(parametersInfos, format);
    for (int cpt = 0; format[cpt] != '\0';) {
        if (format[cpt + 1] == '%' && format[cpt] == '%') {
            my_putchar('%');
            cpt = cpt + 2;
            continue;
        }
        if (format[cpt] == '%') {
            argument_select(format, parametersInfos, &cpt);
            cpt = cpt + 2;
        } else {
            my_putchar(format[cpt]);
            cpt++;
        }
    }
}
