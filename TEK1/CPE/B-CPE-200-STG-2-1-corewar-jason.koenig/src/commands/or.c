/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** or.c
*/

#include "../../include/project.h"

static int add_remain(int i, char *arg, int time)
{
    int sum = 0;

    for (; i > -1; --i)
        if (arg[i] == '1'){
            sum += n_power(2, time);
            ++time;
        }
    return sum;
}

static int get_sum(char *arg1, char *arg2)
{
    int i1 = my_strlen(arg1) - 1;
    int i2 = my_strlen(arg2) - 1;
    int sum = 0;
    int time = 0;

    for (; i2 > -1 && i1 > -1; --i1){
        if (arg1[i1] == '1' || arg2[i2] == '1')
            sum += n_power(2, time);
        --i2;
        ++time;
    }
    sum += add_remain(i1, arg1, time);
    sum += add_remain(i2, arg2, time);
    return sum;
}

void cor_or(corebag_t *bag)
{
    int sum;
    char *arg1;
    char *arg2;

    if (bag->arg1_type == REGISTER)
        bag->arg1 = get_register(bag->arg1, bag->champion);
    if (bag->arg2_type == REGISTER)
        bag->arg2 = get_register(bag->arg2, bag->champion);
    get_indirect(REG_SIZE, bag);
    arg1 = n_base(bag->arg1, 2);
    arg2 = n_base(bag->arg2, 2);
    sum = get_sum(arg1, arg2);
    put_register(bag->arg3, sum, bag->champion);
    bag->champion->carry = get_carry(bag->arg3, bag->champion);
    free(arg1);
    free(arg2);
}
