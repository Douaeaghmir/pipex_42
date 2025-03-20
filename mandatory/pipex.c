#include "pipex.h"

static void child(int *pfd, char **av, char **env)
{
    int fd = 0;
    if(!av || !env)
        return;
    close(pfd[0]);
    // fd = open_file(av[1], 0);
    fd = open(av[1], O_RDONLY, 0777);
    if (fd < 0)
    {   
        close(pfd[1]);
        exit(1);
    }
    dup2(fd, 0);
    close(fd);
    dup2(pfd[1], 1);
    close(pfd[1]);
    exe_cmd(av[2],env);
}
static void parent(int *pfd, char **av, char **env)
{
    int fd;
    if(!av || !env)
        return;
    close(pfd[1]);
    fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
    if(fd < 0)
    {
        close(pfd[0]);
        exit(1);
    }
    dup2(fd, 1);
    close(fd);
    dup2(pfd[0], 0);
    close(pfd[0]);
    exe_cmd(av[3],env);
}
int main(int ac, char **av,char **env)
{
    int fd_p[2];
    pid_t pid;
    pid_t pid2;
    if(ac != 5)
    {
        ft_putstr_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
        exit(EXIT_FAILURE);
    }
    if(pipe(fd_p) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if(pid == -1)
    {
        close(fd_p[0]);
        close(fd_p[1]);
        exit(EXIT_FAILURE);
    }
    if(pid == 0)
        child(fd_p, av, env);
    pid2 = fork();
    if(pid2 == -1)
    {
        close(fd_p[0]);
        close(fd_p[1]);
        exit(EXIT_FAILURE);
    }
    if(pid2 == 0)
        parent(fd_p, av, env);
    close(fd_p[1]);
    close(fd_p[0]);
    wait(NULL);
    wait(NULL);

}