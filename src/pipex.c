/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:40 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/28 17:32:58 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		if (parent_pid != -1)
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
