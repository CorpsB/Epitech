/*
** EPITECH PROJECT, 2023
** ISNEG
** File description:
** display if the number is positive or negative
*/

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}
