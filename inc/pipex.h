/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozerbib- <ozerbib-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:03 by ozerbib-          #+#    #+#             */
/*   Updated: 2023/06/15 14:03:34 by ozerbib-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/*UTILS*/
char	*get_path(char **envp);
char	*right_path(char *oldPath, char *cmd);
int		ult_free_array(char **arr);
void	err(const char *type);
void	run(char *cmd, char **envp);

#endif