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
	char	*command[2];
	char	*extension[2];
}					t_cmd;

typedef struct s_file {
	char*	file[2];
}			t_file;

/*UTILS*/
int 	fill_file_struct(t_file *file, char* inFile, char* outFile);
int		fill_cmd_struct(t_cmd *cmd, char* command1, char* command2);
int 	open_files(t_file file);
char*   get_path(char** envp);
char*   right_path(char* oldPath, char* cmd);

#endif