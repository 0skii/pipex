#include "../inc/pipex.h"

char**  parse(const char* str/*, t_file *file, t_cmd *cmd*/)
{
    int i;
    char** ret = ft_split(str, 32);

    for (i = 0; ret[i]; i++)
        printf("%s\n", ret[i]);
    return (ret);
}