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

void	print_list(t_head *list)
{
	t_cmd	*x;

	x = list->first;
	while (x)
	{
		ft_printf("%s -> ", x->command);
		x = x->next;
	}
	write(1, "NULL\n", 6);
}

int	last_av(char** av)
{
	int	i;

	i = 0;
	while(av[i + 1])
		i++;
	return i;
}