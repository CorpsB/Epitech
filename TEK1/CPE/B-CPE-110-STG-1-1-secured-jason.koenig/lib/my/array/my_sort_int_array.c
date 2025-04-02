/*
** EPITECH PROJECT, 2023
** MY_SORT_INT_ARRAY
** File description:
** Sort an array of integers using bubble sort.
*/

#include "../../../include/my.h"
static void my_sort_2(int *array, int j)
{
    int tmp;

    if (array[j] > array[j + 1]){
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < (size - 1); ++i)
        for (int j = 0; j < (size - i - 1); ++j)
            my_sort_2(array, j);
}
