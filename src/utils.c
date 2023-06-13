#include "../inc/pipex.h"

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


void    run(char *cmd, char **envp)
{
	char	**exec_cmd;
	char	*path;
	int		k;

	exec_cmd = ft_split(cmd, ' ');
	cmd = *exec_cmd;
	path = right_path(get_path(envp), cmd);
	if (!path)
	{
		k = 0;
		while (exec_cmd[k])
		{	
			free(exec_cmd[k]);
			k++;
		}
		free(exec_cmd);
		err("Failed to locate path!");
	}
	if (execve(path, exec_cmd, envp) == -1)
		err("execve");
}