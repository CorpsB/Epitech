/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-robotfactory-thibaut.louis
** File description:
** header.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


static void parse_line_fct(size_t name_len, header_t *header)
{
    if (name_len >= sizeof(header->prog_name))
        name_len = sizeof(header->prog_name) - 1;
}

void parse_name_line(char *line, header_t *header)
{
    char *start = strchr(line, '"');
    char *end;
    size_t name_len;

    if (start) {
        start++;
        end = strchr(start, '"');
        if (end) {
            name_len = end - start;
            parse_line_fct(name_len, header);
            my_strncpy(header->prog_name, start, name_len);
            header->prog_name[name_len] = '\0';
        }
    }
}

void comment_len_fct(size_t comment_len, header_t *header)
{
    if (comment_len >= sizeof(header->comment))
        comment_len = sizeof(header->comment) - 1;
}

void parse_comment_line(char *line, header_t *header)
{
    char *start = strchr(line, '"');
    char *end;
    size_t comment_len;

    if (start) {
        start++;
        end = strchr(start, '"');
        if (end) {
            comment_len = end - start;
            comment_len_fct(comment_len, header);
            my_strncpy(header->comment, start, comment_len);
            header->comment[comment_len] = '\0';
        }
    }
}

void parse_header(FILE *file, header_t *header)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    my_memset(header, 0, sizeof(header_t));
    header->magic = COREWAR_EXEC_MAGIC;
    while ((read = getline(&line, &len, file)) != -1) {
        if (my_strncmp(line, ".name", 5) == 0)
            parse_name_line(line, header);
        if (my_strncmp(line, ".comment", 8) == 0)
            parse_comment_line(line, header);
        if (line[0] != '#' && line[0] != '\n') {
            fseek(file, -read, SEEK_CUR);
            break;
        }
    }
    free(line);
}

void write_header(FILE *output, header_t *header)
{
    uint8_t padding[HEADER_SIZE - sizeof(header_t)] = {0};
    uint32_t prog_size = 0;

    reverse_bytes(&header->magic, sizeof(header->magic));
    fwrite(&header->magic, sizeof(header->magic), 1, output);
    fwrite(header->prog_name, PROG_NAME_LENGTH, 1, output);
    fwrite(&prog_size, sizeof(prog_size), 1, output);
    fwrite(header->comment, COMMENT_LENGTH, 1, output);
    fwrite(padding, sizeof(padding), 1, output);
}
