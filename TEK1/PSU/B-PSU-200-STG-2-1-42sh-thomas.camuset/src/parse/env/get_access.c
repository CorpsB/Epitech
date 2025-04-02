/*
** EPITECH PROJECT, 2024
** ACCESS FILES
** File description:
** Verify the existence and the exec possibility.
*/

#include "../../../include/shell.h"

char *path_retriever(char *name, char **pathlist)
{
    char *pathfind = NULL;

    if (pathlist == NULL)
        return NULL;
    for (int i = 0; pathlist[i] != NULL; ++i){
        if (pathfind != NULL)
            free(pathfind);
        pathfind = my_strdup(pathlist[i]);
        if (pathlist[i][my_strlen(pathlist[i]) - 1] != '/')
            pathfind = s_sepmerge(pathfind, name, '/');
        else
            pathfind = my_strcat(pathfind, name);
        if (access(pathfind, F_OK | R_OK | X_OK) != -1)
            return pathfind;
    }
    free(pathfind);
    return NULL;
}
