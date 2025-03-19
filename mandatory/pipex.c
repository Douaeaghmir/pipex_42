#include "pipex.h"
void child(int fd, char **av, char **env)
{
    int fd;
    char *path;
    char *temp;
    char **tmp;
    char **args;

    if(!av || !env)
        error();
    tmp = ft_split(av[3],' ');

}
int main(int ac, char **av)
{
    if(ac != 5)
    {
        ft_putstr_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
        exit(EXIT_FAILURE);
    }
}