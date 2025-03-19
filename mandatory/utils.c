#include "pipex.c"

char *get_path(char *cmd, char **env)
{
    int i = 0;
    char **pathet;
    char *join_path;
    char *final_path;
    if(!env)
        return(NULL);
    while(env[i] && ft_strnstr(env[i], "PATH", 4))
        i++;
    i = 0;
    pathet = ft_split(env[i] + 5, ":");
    while(pathet[i])
    {
    join_path = ft_strjoin(pathet, "/");
    final_path = ft_strjoin(join_path, cmd);
    free(join_path);
       if(access(final_path, F_OK) == 0)
       {
           return(final_path);
        }
        free(join_path);
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
