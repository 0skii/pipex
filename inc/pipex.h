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
int		fill_cmd_struct(t_head *head, char** av);
int 	open_files(char* in_name, char* out_name);
char*   get_path(char** envp);
char*   right_path(char* oldPath, char* cmd);
t_cmd	*last_pos(t_head *list);
int		ult_list_free(t_cmd *node);
int		ult_free_array(char** arr);
void	print_list(t_head *list);
int		last_av(char** av);

#endif