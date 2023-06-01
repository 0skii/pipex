#include "../inc/pipex.h"

int main(int ac, char** av, char** envp)
{
    t_file  file;
    t_cmd   *head;

    head = NULL;
    if (ac >= 2){
        fill_file_struct(&file, av[1], av[4]);
        fill_cmd_struct(&head, av[2]);
        fill_cmd_struct(&head, av[3]);
        open_files(file);
        char*   path1 = right_path(get_path(envp), head->command);
        char*   path2 = right_path(get_path(envp), head->next->command);
        ft_printf("path for %s is: %s\n", head->command, path1);
        ft_printf("path for %s is: %s\n", head->next->command, path2);
        free(file.file[0]);
        free(file.file[1]);
        free(path1);
        free(path2);
        ult_list_free(head);
    }
    return 0;
}