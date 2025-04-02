/*
** EPITECH PROJECT, 2024
** MY_READ
** File description:
** Return the content of a file using open.
*/

#include "../../../include/my.h"

char *my_readfile(char *pathname)
{
    char *result;
    char buff[1024];
    int bytes_read = 1023;
    int fd = open(pathname, O_RDONLY);

    if (fd == -1)
        return NULL;
    result = my_strdup("");
    while (bytes_read == 1023){
        bytes_read = read(fd, &buff, 1023);
        if (bytes_read != 1023)
            break;
        buff[1023] = '\0';
        result = my_strcat(result, buff);
    }
    if (buff[0] != '\0'){
        buff[bytes_read - 1] = '\0';
        result = my_strcat(result, buff);
    }
    return result;
}
