/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-robotfactory-thibaut.louis
** File description:
** opcode.c
*/

#include "../include/my.h"

static int opcode_get(const char *instr)
{
    if (my_strcmp(instr, "ldi") == 0)
        return 0x0a;
    if (my_strcmp(instr, "sti") == 0)
        return 0x0b;
    if (my_strcmp(instr, "fork") == 0)
        return 0x0c;
    if (my_strcmp(instr, "lld") == 0)
        return 0x0d;
    if (my_strcmp(instr, "lldi") == 0)
        return 0x0e;
    if (my_strcmp(instr, "lfork") == 0)
        return 0x0f;
    if (my_strcmp(instr, "aff") == 0)
        return 0x10;
    if (my_strcmp(instr, "zjmp") == 0)
        return 0x09;
    return -1;
}

int get_opcode(const char *instr)
{
    if (my_strcmp(instr, "live") == 0)
        return 0x01;
    if (my_strcmp(instr, "ld") == 0)
        return 0x02;
    if (my_strcmp(instr, "st") == 0)
        return 0x03;
    if (my_strcmp(instr, "add") == 0)
        return 0x04;
    if (my_strcmp(instr, "sub") == 0)
        return 0x05;
    if (my_strcmp(instr, "and") == 0)
        return 0x06;
    if (my_strcmp(instr, "or") == 0)
        return 0x07;
    if (my_strcmp(instr, "xor") == 0)
        return 0x08;
    opcode_get(instr);
    return -1;
}
