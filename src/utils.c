/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:27 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/22 17:15:47 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_init_pipe(void)
{
	int		pipe_fd[2];
	pid_t	pid;
	// char	buf;
	
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	// int fd = open("jajaja", O_RDONLY);
	// if (fd < 0)
	// {
	// 	perror("open");
	// 	printf("pepe\n");
	// 	exit(EXIT_FAILURE);
	// }
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		ft_printf("Hijo\n");
	}
	else
	{
		ft_printf("Padre\n");
	}
}