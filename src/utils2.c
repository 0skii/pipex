#include "../inc/pipex.h"

int	ult_list_free(t_cmd *node)
{
	while (node)
	{
		free(node->command);
		free(node->pathname);
		node = node->next;
	}
	return 0;
}

int	ult_free_array(char** arr)
{
	int	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
	return 0;
}

void	err(const char* type)
{
	perror(type);
	exit(EXIT_FAILURE);
}