#include "../inc/pipex.h"

t_cmd	*last_pos(t_head *list)
{
	t_cmd	*x;

	if (!list)
		return (NULL);
	x = list->first;
	while (x && x->next)
		x = x->next;
	return (x);
}

int	ult_list_free(t_cmd *node)
{
	if (node->next)
		ult_list_free(node->next);
	free(node);
	return (0);
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
