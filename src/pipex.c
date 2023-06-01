#include "../inc/pipex.h"

int main(int ac, char** av, char** envp)
{
    t_file  file;
    t_cmd   cmd;
    
    if (ac >= 2){
        fill_file_struct(&file, av[1], av[4]);
        fill_cmd_struct(&cmd, av[2], av[3]);
        open_files(file);
        ft_printf("path for %s is: %s\n", cmd.command[0], right_path(get_path(envp), cmd.command[0]));
        ft_printf("path for %s is: %s\n", cmd.command[1], right_path(get_path(envp), cmd.command[1]));
        free(file.file[0]);
        free(file.file[1]);
        free(cmd.command[0]);
        free(cmd.command[1]);
    }
    return 0;
}