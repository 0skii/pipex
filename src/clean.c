/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:23:39 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/06/15 14:05:18 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ult_free_array(char	**arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
	return (0);
}

void	err(const char *type)
{
	perror(type);
	exit(EXIT_FAILURE);
}
