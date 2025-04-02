/*
** EPITECH PROJECT, 2024
** DIRECTORY HANDLER
** File description:
** Change working directory.
*/

#include "../../../include/shell.h"

static int is_a_directory(char *path)
{
    struct stat sa;

    stat(path, &sa);
    if (S_ISDIR(sa.st_mode))
        return 1;
    return 0;
}

static void edit_cwd_variable(storage_bag_t *storage, char new_path[1000])
{
    char **cwd_tab = malloc(sizeof(char *) * 4);

    cwd_tab[0] = "set";
    cwd_tab[1] = "cwd=";
    cwd_tab[2] = new_path;
    cwd_tab[3] = NULL;
    set(storage, cwd_tab);
    free(cwd_tab);
    exec_cwdcmd(storage);
}

int change_path(storage_bag_t *storage, char *path)
{
    int exit_code;
    char old_path[1000];
    char new_path[1000];
    int pathline;

    if (access(path, F_OK) == -1)
        return msg(ERR, 2, 2, path, ": No such file or directory.\n");
    if (access(path, R_OK) == -1)
        return msg(ERR, 2, 2, path, ": Permission denied.\n");
    if (!is_a_directory(path))
        return msg(ERR, 2, 2, path, ": Not a directory.\n");
    getcwd(old_path, 1000);
    exit_code = chdir(path);
    if (exit_code != 0)
        return exit_code;
    choice_set_method(storage, "OLDPWD", old_path);
    getcwd(new_path, 1000);
    choice_set_method(storage, "PWD", new_path);
    edit_cwd_variable(storage, new_path);
    return 0;
}

int change_wd(storage_bag_t *storage, char *path)
{
    int exit_code;
    char *varpath;

    if (!(path[0] == '-' && path[1] == '\0'))
        return change_path(storage, path);
    varpath = get_variable(storage->env, "OLDPWD");
    if (varpath == NULL)
        return msg(ERR, 2, 1, ": No such file or directory.\n");
    exit_code = change_path(storage, varpath);
    free(varpath);
    return exit_code;
}

int change_directory(storage_bag_t *storage, char **data)
{
    int size = a_size(data);
    char *home_dir;
    int exit_code;

    if (size > 2)
        return msg(ERR, 2, 1, "cd: Too many arguments.\n");
    if (size == 2)
        if (!(data[1][0] == '~' && data[1][1] == '\0'))
            return change_wd(storage, data[1]);
    home_dir = get_variable(storage->env, "HOME");
    if (home_dir == NULL)
        return msg(ERR, 2, 1, "cd: No home directory.\n");
    exit_code = change_path(storage, home_dir);
    free(home_dir);
    return exit_code;
}
