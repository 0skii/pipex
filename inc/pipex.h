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
	char*			command;
	char*			pathname;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_head {
	t_cmd	*first;
}			t_head;

typedef struct s_file {
	char*	file[2];
}			t_file;

/*UTILS*/
int 	fill_file_struct(t_file *file, char* inFile, char* outFile);
int		fill_cmd_struct(t_cmd **head, char* command);
int 	open_files(t_file file);
char*   get_path(char** envp);
char*   right_path(char* oldPath, char* cmd);
t_cmd	*last_pos(t_head *list);
int		ult_list_free(t_cmd *node);
int		ult_free_array(char** arr);

#endif