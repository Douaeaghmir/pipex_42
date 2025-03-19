#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(const char *s);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void failed(void *msg);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void error(void);
#endif