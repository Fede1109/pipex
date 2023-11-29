/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:18:18 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/29 17:30:37 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

char	*get_cmd_route(char *path, char	*cmd)
{
	char	**possible_path;
	char	*cmd_route;
	char	*aux_route;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strtrim(path, "PATH=");
	possible_path = ft_split(aux, ':');
	while (possible_path[i])
	{
		aux_route = ft_strjoin(possible_path[i], "/");
		cmd_route = ft_strjoin(aux_route, cmd);
		if (access(cmd_route, F_OK) != -1 && access(cmd_route, X_OK) != -1)
			break ;
		else
			free(cmd_route);
		i++;
	}
	free(aux);
	return (cmd_route);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	parent_pid;

	if (argc != 5 || pipe(pipe_fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		child_process(argv, pipe_fd, envp);
	else
	{
		parent_pid = fork();
		if (parent_pid == -1)
			ft_error();
		if (parent_pid == 0)
			parent_process(argv, pipe_fd, envp);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(parent_pid, NULL, 0);
	}
	return (0);
}
