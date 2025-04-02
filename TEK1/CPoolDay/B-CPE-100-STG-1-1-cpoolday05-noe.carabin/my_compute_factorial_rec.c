/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_FACTORIAL_REC
** File description:
** write a factorial with a recursive nfonction
*/
int my_compute_factorial_rec(nb)
{
    if (nb == 0) {
        return (1);
    }
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    return (normal_case(nb));
}

int normal_case(int nb)
{
    if ((nb -1) == 0) {
        return (nb);
    }
    nb = nb * my_compute_factorial_rec(nb - 1);
}
