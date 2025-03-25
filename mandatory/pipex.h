#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>


char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(const char *s);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void failed(void *msg);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void error(void);
int open_file(char *file,int io);
void free_array(char **arr);
void exe_cmd(char *arg, char **env);
char *get_path(char *cmd, char **env);
void ft_notcomand(void);
void ft_close(int *fd);
#endif