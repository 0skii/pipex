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
    const char		*content;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_file {
	const char*	file[2];
}				t_file;

char**  parse(const char* str/*, t_file *file, t_cmd *cmd*/);

#endif