/*
** EPITECH PROJECT, 2023
** my print comb
** File description:
** write number (max 999) with 3 different numbers.
*/

int select(int i, int j, int k)
{
    if (i != j && i != k && j != k && k<j && k<i && j<i) {
        my_putchar(k + 48);
        my_putchar(j + 48);
        my_putchar(i + 48);
        my_putchar(44);
        my_putchar(32);
    }
}

int fstop(int i, int j, int k)
{
    if (k == 7 && j == 8 && i == 9){
        my_putchar(k + 48);
        my_putchar(j + 48);
        my_putchar(i + 48);
        return 2;
    }
    return 0;
}

int exchange_j(int *j, int *k)
{
    if (*j > 9) {
        *j = 0;
        return *k = *k + 1;
    }
}

int my_print_comb(void)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int stop = 0;

    for (k = 0; j < 10; i++) {
        if (i > 9){
            j = j + 1;
            i = 0;
        }
        exchange_j(&j, &k);
        stop = fstop(i, j, k);
        if (stop > 0){
            return 0;
        }
        select(i, j, k);
    }
}
