/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-jason.koenig
** File description:
** register.c
*/

#include "../../include/project.h"

static void insert_value(char reg[REG_SIZE * 2 + 1], int value)
{
    char *str_value = get_hexa_base(value, REG_SIZE * 2);

    init_register(reg);
    s_copy(reg, str_value);
    free(str_value);
}

static void put_register_next(int number, int value,
    champions_t *champion)
{
    if (number == 9)
        insert_value(champion->r9, value);
    if (number == 10)
        insert_value(champion->r10, value);
    if (number == 11)
        insert_value(champion->r11, value);
    if (number == 12)
        insert_value(champion->r12, value);
    if (number == 13)
        insert_value(champion->r13, value);
    if (number == 14)
        insert_value(champion->r14, value);
    if (number == 15)
        insert_value(champion->r15, value);
    if (number == 16)
        insert_value(champion->r16, value);
}

void put_register(int number, int value, champions_t *champion)
{
    if (number > 8)
        put_register_next(number, value, champion);
    if (number == 1)
        insert_value(champion->r1, value);
    if (number == 2)
        insert_value(champion->r2, value);
    if (number == 3)
        insert_value(champion->r3, value);
    if (number == 4)
        insert_value(champion->r4, value);
    if (number == 5)
        insert_value(champion->r5, value);
    if (number == 6)
        insert_value(champion->r6, value);
    if (number == 7)
        insert_value(champion->r7, value);
    if (number == 8)
        insert_value(champion->r8, value);
}

static int get_register_next(int number, champions_t *champion)
{
    if (number == 9)
        return n_revbase(champion->r9, 16, REG_SIZE * 2);
    if (number == 10)
        return n_revbase(champion->r10, 16, REG_SIZE * 2);
    if (number == 11)
        return n_revbase(champion->r11, 16, REG_SIZE * 2);
    if (number == 12)
        return n_revbase(champion->r12, 16, REG_SIZE * 2);
    if (number == 13)
        return n_revbase(champion->r13, 16, REG_SIZE * 2);
    if (number == 14)
        return n_revbase(champion->r14, 16, REG_SIZE * 2);
    if (number == 15)
        return n_revbase(champion->r15, 16, REG_SIZE * 2);
    if (number == 16)
        return n_revbase(champion->r16, 16, REG_SIZE * 2);
    return -1;
}

int get_register(int number, champions_t *champion)
{
    if (number > 8)
        return get_register_next(number, champion);
    if (number == 1)
        return n_revbase(champion->r1, 16, REG_SIZE * 2);
    if (number == 2)
        return n_revbase(champion->r2, 16, REG_SIZE * 2);
    if (number == 3)
        return n_revbase(champion->r3, 16, REG_SIZE * 2);
    if (number == 4)
        return n_revbase(champion->r4, 16, REG_SIZE * 2);
    if (number == 5)
        return n_revbase(champion->r5, 16, REG_SIZE * 2);
    if (number == 6)
        return n_revbase(champion->r6, 16, REG_SIZE * 2);
    if (number == 7)
        return n_revbase(champion->r7, 16, REG_SIZE * 2);
    if (number == 8)
        return n_revbase(champion->r8, 16, REG_SIZE * 2);
}
