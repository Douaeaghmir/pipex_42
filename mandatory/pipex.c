/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:27:07 by doaghmir          #+#    #+#             */
/*   Updated: 2025/03/26 01:36:16 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int *pfd, char **av, char **env)
{
	int	fd;

	fd = 0;
	if (!av || !env)
		return ;
	close(pfd[0]);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		write(2, "no such file or directory\n", 26);
		close(pfd[1]);
		exit(1);
	}
	dup2(fd, 0);
	close(fd);
	dup2(pfd[1], 1);
	close(pfd[1]);
	exe_cmd(av[2], env);
}

static void	child2(int *pfd, char **av, char **env)
{
	int	fd;

	if (!av || !env)
		return ;
	close(pfd[1]);
	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "no such file or directory\n", 26);
		close(pfd[0]);
		exit(1);
	}
	dup2(fd, 1);
	close(fd);
	dup2(pfd[0], 0);
	close(pfd[0]);
	exe_cmd(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd_p[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5)
		ft_notcomand();
	if (pipe(fd_p) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_close(fd_p);
	if (pid == 0)
		child(fd_p, av, env);
	pid2 = fork();
	if (pid2 == -1)
		ft_close(fd_p);
	if (pid2 == 0)
		child2(fd_p, av, env);
	close(fd_p[1]);
	close(fd_p[0]);
	wait(NULL);
	wait(NULL);
}
