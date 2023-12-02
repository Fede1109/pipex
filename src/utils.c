/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:03:27 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/12/01 17:40:44 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*get_route(char **envp)
{
	int		i;
	char	*envp_path;
	char	*cmd_route;

	i = 0;
	envp_path = NULL;
	cmd_route = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			envp_path = envp[i];
			return (envp_path);
		}
		i++;
	}
	ft_error();
	return (NULL);
}

void	execute_command(char *argv, char **envp)
{
	char	**cmd;
	char	*route;
	char	*aux;

	cmd = ft_split(argv, ' ');
	aux = get_route(envp);
	route = get_cmd_route(aux, cmd[0]);
	if (execve(route, cmd, envp) == -1)
		ft_error();
}

void	child_process(char **argv, int *fd, char **envp)
{
	int	file_fd;

	close(fd[0]);
	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		ft_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error();
	if (dup2(file_fd, STDIN_FILENO) == -1)
		ft_error();
	close(fd[1]);
	execute_command(argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int	file_fd;

	close(fd[1]);
	file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd == -1)
		ft_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	if (dup2(file_fd, STDOUT_FILENO) == -1)
		ft_error();	
	close(fd[0]);
	execute_command(argv[3], envp);
}
