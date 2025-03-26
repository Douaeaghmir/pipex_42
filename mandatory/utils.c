/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:27:12 by doaghmir          #+#    #+#             */
/*   Updated: 2025/03/26 01:35:26 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**pathet;
	char	*join_path;
	char	*final_path;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	pathet = ft_split(env[i] + 5, ':');
	i = 0;
	while (pathet[i])
	{
		join_path = ft_strjoin(pathet[i], "/");
		final_path = ft_strjoin(join_path, cmd);
		free(join_path);
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		i++;
	}
	free_array(pathet);
	puts("errr\n");
	return (failed("command not found\n"), NULL);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	file_opener(char *file, int io)
{
	int	x;

	if (!file)
		return (-1);
	if (io == 0)
	{
		if (access(file, F_OK) != 0)
			ft_putstr_fd("no such file pr directory\n", 2);
		else
			x = open(file, O_RDONLY, 0777);
	}
	if (io == 1)
		x = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (x == -1)
		exit(EXIT_FAILURE);
	return (x);
}

void	exe_cmd(char *arg, char **env)
{
	char	**cmd;
	char	*path;

	if (!env)
		return ;
	cmd = ft_split(arg, ' ');
	if (access(arg, X_OK) == 0)
	{
		execve(cmd[0], cmd, env);
		return ;
	}
	path = get_path(cmd[0], env);
	if (!path)
	{
		free_array(cmd);
		error();
	}
	if (execve(path, cmd, env) == -1)
	{
		error();
	}
}
