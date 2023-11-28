/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:27 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/28 19:03:29 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
//*PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/share/dotnet:/usr/local/munki:~/.dotnet/tools:/Library/Frameworks/Mono.framework/Versions/Current/Commands
char	*get_route(char **envp)
{
	
}

void	execute_command(char **argv, char **envp)
{
	char	**cmd;
	char	*route;

	cmd = ft_split(argv, " ");
	route = get_route(envp);
	if (execve(route, cmd, envp) == -1)
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
