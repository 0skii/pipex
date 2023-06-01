#include "../inc/pipex.h"

int main(int ac, char** av, char** envp)
{
    t_file  file;
    
    if (ac >= 2){
        fill_file_struct(&file, av[1], av[4]);
        open_files(file);
        printf("%s\n", right_path(get_path(envp), "ls"));
        free(file.file[0]);
        free(file.file[1]);
    }
    return 0;
}