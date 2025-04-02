/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** tabs
*/

#include "../../../include/shell.h"

static file_data_t free_return(char ***arr, char **str,
    file_data_t data)
{
    free(*str);
    a_free(*arr);
    return data;
}

static int get_command_position(char *str, int cursor_offset)
{
    int count = 1;

    if (cursor_offset > strlen(str))
        return -1;
    for (int i = 0; i < cursor_offset; i++)
        if (str[i] == ' ' && str[i + 1] != ' ')
            count++;
    return count;
}

static void modify_command_next(file_data_t *f_data, char **tmp)
{
    if (my_strncmp(f_data->directory, "./", 2) != 0)
        *tmp = my_strcat_no_free(f_data->directory, f_data->f_name);
    else
        *tmp = my_strdup(f_data->f_name);
}

static void modify_command(storage_bag_t *storage, file_data_t *f_data,
    file_t *files, int offset)
{
    char **command_arr = NULL;
    char *tmp = NULL;
    char w_dir[1000];

    getcwd(w_dir, 1000);
    command_arr = a_convert_s(storage->prompt.command, ' ', '\t');
    free(f_data->f_name);
    f_data->f_name = my_strdup(files->data);
    modify_command_next(f_data, &tmp);
    free(command_arr[offset - 1]);
    command_arr[offset - 1] = my_strdup(tmp);
    for (int i = 0; i < storage->prompt.cursor_offset; i++)
        printf("\b");
    printf("\033[0K");
    free(storage->prompt.command);
    storage->prompt.command = s_convert_a(command_arr, 0);
    printf("%s", storage->prompt.command);
    storage->prompt.cursor_offset = strlen(storage->prompt.command);
    a_free(command_arr);
    free(tmp);
}

static void print_files(storage_bag_t *storage,
    file_t *files, file_data_t *f_data, int offset)
{
    char w_dir[1000];
    char *tmp = NULL;

    getcwd(w_dir, 1000);
    if (count_files_in_folder(files) > 1){
        display_files(files);
        print_prompt_exit_code(storage, w_dir);
        my_putstr(storage->prompt.command, 1);
        for (int i = 0; i < (my_strlen(storage->prompt.command) -
            storage->prompt.cursor_offset); i++)
            my_putstr("\033[D", 1);
    } else if (count_files_in_folder(files) == 1){
        modify_command(storage, f_data, files, offset);
    } else
        printf("\a");
}

static char *clean_f_name(char *str)
{
    char *result = NULL;
    int result_len = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ';' && str[i] != '|')
            result_len++;
    result = malloc(sizeof(char) * (result_len + 1));
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ';' && str[i] != '|'){
            result[j] = str[i];
            j++;
        }
    }
    free(str);
    result[j] = '\0';
    return result;
}

static void get_file_data_next(char *str, vector3i_t *x, int *slash_c)
{
    (*x).z = strlen(str);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '/'){
            (*x).y = i + 1;
            (*slash_c)++;
        }
    }
}

file_data_t get_file_data(char *command, int offset)
{
    file_data_t result;
    char **command_arr = NULL;
    char *str = NULL;
    int slash_c = 0;
    vector3i_t x = {0, 0, 0};

    command_arr = a_convert_s(command, ' ', '\t');
    if (command_arr == NULL)
        str = my_strdup("");
    else
        str = my_strdup(command_arr[offset - 1]);
    get_file_data_next(str, &x, &slash_c);
    if (slash_c <= 0)
        result.directory = my_strdup("./");
    else
        result.directory = my_substr(str, x.x, x.y);
    result.f_name = my_substr(str, x.y, x.z);
    result.f_name = clean_f_name(result.f_name);
    return free_return(&command_arr, &str, result);
}

void exec_tabs(storage_bag_t *storage)
{
    file_t *files = NULL;
    file_data_t file_data;
    char w_dir[1000];
    int command_pos = 1;

    getcwd(w_dir, 1000);
    command_pos = get_command_position(storage->prompt.command,
        storage->prompt.cursor_offset);
    file_data = get_file_data(storage->prompt.command, command_pos);
    if (command_pos == 1){
        for (int i = 0; storage->pathlist[i] != NULL; i++)
            fill_files(&files, storage->pathlist[i], file_data.f_name);
        print_files(storage, files, &file_data, command_pos);
    } else {
        fill_files(&files, file_data.directory, file_data.f_name);
        print_files(storage, files, &file_data, command_pos);
    }
    free(file_data.f_name);
    free(file_data.directory);
    free_files(&files);
}
