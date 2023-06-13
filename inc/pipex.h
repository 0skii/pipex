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

typedef struct s_cmd {
	char**			command;
	char*			pathname;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_head {
	t_cmd	*first;
	int		size;
}			t_head;

/*UTILS*/
char*   get_path(char** envp);
char*   right_path(char* oldPath, char* cmd);
int		ult_list_free(t_cmd *node);
int		ult_free_array(char** arr);
void	err(const char* type);
void    run(char *cmd, char **envp);

#endif