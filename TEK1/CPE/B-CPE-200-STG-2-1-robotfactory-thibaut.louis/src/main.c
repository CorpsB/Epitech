/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-robotfactory-thibaut.louis
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../include/my.h"

void reverse_bytes(void *start, int size)
{
    char *lo = start;
    char *hi = lo + size - 1;
    char swap;

    while (lo < hi) {
        swap = *lo;
        *lo = *hi;
        *hi = swap;
        lo++;
        hi--;
    }
}

void parse_params_detail(char **param_array, int output_fd,
    uint32_t *prog_size, int i)
{
    int reg_num;
    int32_t value;
    int16_t value2;

    if (param_array[i][0] == 'r') {
        reg_num = my_atoi(param_array[i] + 1);
        write(output_fd, &reg_num, 1);
        (*prog_size)++;
    } else if (param_array[i][0] == '%') {
        value = my_atoi(param_array[i] + 1);
        reverse_bytes(&value, sizeof(value));
        write(output_fd, &value, sizeof(value));
        (*prog_size) += 4;
    } else {
        value = my_atoi(param_array[i]);
        reverse_bytes(&value, sizeof(value));
        write(output_fd, &value, sizeof(value));
        (*prog_size) += 2;
    }
}

void parse_params(char *params, int output_fd, uint32_t *prog_size)
{
    char **param_array = my_str_to_word_array_upgrade(params, ',', ' ');

    for (int i = 0; param_array[i]; i++) {
        parse_params_detail(param_array, output_fd, prog_size, i);
    }
    free(param_array);
}

static void parse_line(char *line, char *instr, char *params)
{
    char *instr_ptr = strtok(line, " \t\n");
    char *params_ptr;

    if (instr_ptr) {
        my_strncpy(instr, instr_ptr, sizeof(instr) - 1);
        instr[sizeof(instr) - 1] = '\0';
        *params_ptr = strtok(NULL, "\n");
        if (params_ptr) {
            my_strncpy(params, params_ptr, sizeof(params) - 1);
            params[sizeof(params) - 1] = '\0';
        } else {
            params[0] = '\0';
        }
    } else {
        instr[0] = '\0';
        params[0] = '\0';
    }
}

static void write_instruction(const char *instr, const char *params,
    FILE *output, uint32_t *prog_size)
{
    int opcode = get_opcode(instr);
    if (opcode != -1) {
        fwrite(&opcode, sizeof(opcode), 1, output);
        (*prog_size)++;
        if (my_strlen(params) > 0) {
            parse_params(params, output, prog_size);
        }
    }
}

static void parse_instructions(FILE *input, FILE *output, uint32_t *prog_size)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char instr[10];
    char params[256];

    while ((read = getline(&line, &len, input)) != -1) {
        if (line[0] == '\n' || line[0] == '#')
            continue;
        parse_line(line, instr, params);
        if (instr[0] != '\0') {
            write_instruction(instr, params, output, prog_size);
        }
    }
    free(line);
}

static void write_prog_size(FILE *output, uint32_t prog_size)
{
    fseek(output, sizeof(uint32_t) + PROG_NAME_LENGTH, SEEK_SET);
    reverse_bytes(&prog_size, sizeof(prog_size));
    fwrite(&prog_size, sizeof(prog_size), 1, output);
}

static void process_files(FILE *input_file, FILE *output_file)
{
    header_t header;
    uint32_t prog_size = 0;

    parse_header(input_file, &header);
    write_header(output_file, &header);
    parse_instructions(input_file, output_file, &prog_size);
    write_prog_size(output_file, prog_size);
}

int main(int ac, char **av)
{
    FILE *input_file = fopen(av[1], "r");
    char output_file_name[256];
    FILE *output_file;
    char *ext;

    if (my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 0;
    }
    if (ac != 2 || !input_file)
        return 84;
    my_strcpy(output_file_name, av[1]);
    ext = strrchr(output_file_name, '.');
    if (ext)
        my_strcpy(ext, ".cor");
    else
        my_str_cat2(output_file_name, ".cor");
    output_file = fopen(output_file_name, "wb");
    if (!output_file) {
        fclose(input_file);
        return 84;
    }
    process_files(input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}
