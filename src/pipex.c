#include "../inc/pipex.h"

int main(int ac, char** av, char** envp)
{
    (void)envp;
    static t_head    *head;
    static t_cmd     *cmd;
    int              i;

    if (ac < 5)
    {
        write(STDERR_FILENO, "Syntax Error! (./pipex infile cmd1 cmd2 ... outfile)\n", 53);
        exit(EXIT_FAILURE);
    }
    fill_cmd_struct(head, av);
    i = 0;
    while (cmd)
    {
        ft_printf("%s\n", cmd->command[i]);
        i++;
        cmd = cmd->next;
    }
}