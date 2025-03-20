#include "pipex.h"

char *get_path(char *cmd, char **env)
{
    int i = 0;
    char **pathet;
    char *join_path;
    char *final_path;
    if(!env)
        return(NULL);
    while(env[i] && ft_strnstr(env[i], "PATH", 4) == 0) // check this out
        i++;
    pathet = ft_split(env[i] + 5, ':');
    i = 0;
    while(pathet[i])
    {
    join_path = ft_strjoin(pathet[i], "/");
    final_path = ft_strjoin(join_path, cmd);
    free(join_path);
       if(access(final_path, F_OK) == 0)
           return(final_path);
        free(final_path);
        i++;
    }
    free_array(pathet);
    return(failed("command not found"), NULL);
}
void free_array(char **arr)
{
    int i = 0;
    if(!arr)
    return;
    while(arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int open_file(char *file,int fd)
{
    int f;
    if(fd == 0)
    {
        if(access(file, F_OK) != 0)
        {
            ft_putstr_fd("No such file or directory", 2);
            f = -1;
        }
        else
        f = open(file, O_RDONLY| 0777); 
    }
    if(fd == 1)
    {
        f = open(file, O_CREAT | O_RDWR | O_TRUNC , 0777 );
    }
    return(f);
}
void exe_cmd(char *arg, char **env)
{
    char **cmd;
    char *path;
    if(!env)
        return;
    cmd = ft_split(arg, ' ');
    path = get_path(cmd[0],env);
    if(!path)
    {
        free_array(cmd);
        error();
    }
    if(execve(path, cmd, env) == -1)
        error();
}