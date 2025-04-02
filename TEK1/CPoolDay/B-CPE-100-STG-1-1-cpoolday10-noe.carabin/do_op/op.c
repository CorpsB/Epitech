/*
** EPITECH PROJECT, 2023
** do op
** File description:
** make all op
*/

int my_add(int value1, int value2, int *error)
{
    return (value1 + value2);
}

int my_sub(int value1, int value2, int *error)
{
    return (value1 - value2);
}

int my_mul(int value1, int value2, int *error)
{
    return (value1 * value2);
}

int my_div(int value1, int value2, int *error)
{
    if (value2 == 0) {
        *error = 84;
    } else {
        return (value1 / value2);
    }
}

int my_mod(int value1, int value2, int *error)
{
    return (value1 % value2);
}
