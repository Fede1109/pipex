/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:27 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/28 18:19:57 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	execute_command(char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, " ");

	if (execv(, cmd, envp) == -1)
		ft_error();

}

void	child_process(char **argv, int *fd, char **envp)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		ft_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error();
	if (dup2(file_fd, STDIN_FILENO))
		ft_error();
	close(fd[1]);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int	file_fd;

	file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_fd == -1)
		ft_error();
	if (dup2(fd[0], STDIN_FILENO) == 1)
		ft_error();
	if (dup2(file_fd, STDOUT_FILENO))
		ft_error();
	close(fd[0]);
	execute_command(argv[3], envp);
}
