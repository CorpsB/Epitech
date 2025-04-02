/*
** EPITECH PROJECT, 2024
** GET_USER
** File description:
** Get informations about user.
*/

#include "../../../include/shell.h"

void get_userdata(storage_bag_t *storage)
{
    int uid = getuid();
    struct passwd *pw = getpwuid(uid);

    storage->username = my_strdup(pw->pw_name);
    if (gethostname(storage->hostname, 1000) != 0)
        s_copy(storage->hostname, "GANG");
}
