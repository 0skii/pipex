#include "../inc/pipex.h"

int main(int ac, char** av)
{
    if (ac >= 2)
        parse(av[1]);
    return 0;
}