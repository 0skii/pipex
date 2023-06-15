/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:23:25 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/06/15 14:20:32 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	process_1(char **argv, int *arr, char **envp)
{	
	int	in;

	in = open(argv[1], O_RDONLY);
	if (in < 0)
		err("open");
	close(arr[0]);
	dup2(in, STDIN_FILENO);
	dup2(arr[1], STDOUT_FILENO);
	run(argv[2], envp);
}

void	process_2(char **argv, int *arr, char **envp)
{
	int	out;

	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out < 0)
		err("open");
	close(arr[1]);
	dup2(arr[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	run(argv[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int	status;
	int	in_out[2];
	int	p1;
	int	p2;

	if (ac < 5)
	{
		write(STDERR_FILENO, "Syntax Error!\
		(./pipex infile cmd1 cmd2 ... outfile)\n", 54);
		exit(EXIT_FAILURE);
	}
	if (pipe(in_out) < 0)
		err("pipe");
	p1 = fork();
	if (p1 < 0)
		err("fork");
	if (p1 == 0)
		process_1(av, in_out, envp);
	p2 = fork();
	if (p2 < 0)
		err("fork");
	if (p2 == 0)
		process_2(av, in_out, envp);
	waitpid(-1, &status, 0);
	return (0);
}
