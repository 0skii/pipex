#include "../inc/pipex.h"

int fill_file_struct(t_file *file, char* inFile, char* outFile)
{
    if (!inFile || !outFile)
        return 0;
    file->file[0] = ft_strdup(inFile);
    if (!file->file[0])
        return 0;
    file->file[1] = ft_strdup(outFile);
    if (!file->file[1])
        return 0;
    return 1;
}

int fill_cmd_struct(t_cmd **head, char* command)
{
    t_cmd   *data;

	data = (t_cmd *)malloc(sizeof(*data));
	data->command = command;
	data->next = NULL;
	if (!*head)
		*head = data;
	else
        (*head)->next = data;
	return 1;
}

int open_files(t_file file)
{
    int file1 = open(file.file[0], O_RDONLY);
    if (file1 == -1)
        return 0;
    int file2 = open(file.file[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (file2 == -1)
        return 0;
    write(file2, "bomdia", 6);
    return 1;
}

char*   get_path(char** envp)
{
    int index = 0;
    char** ret;
    char *temp;

    while (envp[index])
    {
        ret = ft_split(envp[index], '=');
        if (ret[0][0] == 'P' && ret[0][3] == 'H') {
            temp = ft_strdup(ret[1]);
            ult_free_array(ret);
            return temp;
        }
        index++;
        ult_free_array(ret);
    }
    return NULL;
}

char*   right_path(char* oldPath, char* cmd)
{
    int     index = 0;
    char**  paths = ft_split(oldPath, ':');
    
    free(oldPath);
    while (paths[index])
    {
        char* s1 = ft_strjoin(paths[index], "/");
        char* s2 = ft_strjoin(s1, cmd);
        if (access(s2, F_OK) == 0){
            ult_free_array(paths);
            free(s1);
            return (s2);
        }
        free(s1);
        free(s2);
        index++;
    }
    ult_free_array(paths);
    return NULL;
}