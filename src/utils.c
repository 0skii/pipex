#include "../inc/pipex.h"

int fill_cmd_struct(t_head *head, char** av)
{
    t_cmd   *data;
    int     i;

    i = 2;
    data = head->first;
	while (av[i + 1])
    {
	    data = malloc(sizeof(*data));
        data->command = ft_split(av[i], ' ');
        data = data->next;
        i++;
    }
	return 0;
}

t_head	*new_command(t_head *head, char** av)
{
	t_cmd			*data;
	t_cmd			*x;

	data = (t_cmd *)malloc(sizeof(*data));
	data->command = av;
	data->next = NULL;
	if (!head->first)
		head->first = data;
	else
	{
		x = last_pos(head);
		x->next = data;
	}
	head->size++;
	return 0;
}

int open_files(char* in_name, char* out_name)
{
    int file1 = open(in_name, O_RDONLY);
    if (file1 == -1)
        return 0;
    int file2 = open(out_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (file2 == -1)
        return 0;
    return 1;
}

char*   get_path(char** envp)
{
    int index = 0;

    while (envp[index])
    {
        if (envp[index][0] == 'P' && envp[index][3] == 'H') {
            return (ft_strdup(envp[index] + 5));
        }
        index++;
    }
    return NULL;
}

char*   right_path(char* oldPath, char* cmd)
{
    int     index = 0;
    char**  paths = ft_split(oldPath, ':');
    
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