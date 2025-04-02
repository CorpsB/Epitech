/*
** EPITECH PROJECT, 2023
**  
** File description:
**  
*/

#include <stdarg.h>

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0' ; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number + 1);
}

int sum_strings_length (int n , ...)
{
    va_list a_lot_str;
    va_start(a_lot_str, n);
    int nbr = 0;

    for (int cpt = 0; cpt < n; cpt ++) {
    nbr = nbr + my_strlen(va_arg(a_lot_str, char*));
    }
    va_end(a_lot_str);
    return (nbr - 1);
}

main(void)
{
    printf("%d", sum_strings_length(2, "C est\0" "la fete\0" "est beau\0"));
}
