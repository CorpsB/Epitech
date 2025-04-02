/*
** EPITECH PROJECT, 2023
** COUNT NUMBER
** File description:
** Count the numbers of an integer.
*/

#include "../../includes/my.h"

int kj_count_number(unsigned long long int number)
{
    int counter = 1;

    while ((number / 10) >= 1){
        number = number / 10;
        ++counter;
    }
    return (counter);
}
