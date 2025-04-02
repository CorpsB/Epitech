/*
** EPITECH PROJECT, 2023
** My compute rec
** File description:
** calculate power
*/

int calcul(int nb, int p)
{
    int result;

    if (p == 0) {
        return (nb);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

int my_compute_power_rec(int nb, int p)
{
    return (0);
}
