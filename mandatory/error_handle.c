/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:26:58 by doaghmir          #+#    #+#             */
/*   Updated: 2025/03/26 01:35:49 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	failed(void *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	ft_putstr_fd("error", 2);
}

void	ft_notcomand(void)
{
	ft_putstr_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	exit(EXIT_FAILURE);
}
