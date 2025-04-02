/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-noe.carabin
** File description:
** my.h
*/

#ifndef MY
    #define MY

struct Best {
    int b_larg;
    int b_co;
};

struct define_min {
    int minimal;
    int a;
    int b;
    int c;
};

struct int_table_information {
    int *ta;
    int loc;
    int first_len;
    int count;
    int size;
};

struct moving_string {
    char *string;
    int cpt;
    int file_origin;
    int error;
    int final_size;
};

#endif
