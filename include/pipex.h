/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:03 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/29 11:30:28 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

void	child_process(char **argv, int *fd, char **envp);
void	parent_process(char **argv, int *fd, char **envp);
char	*get_cmd_route(char *path, char	*cmd);
void	execute_command(char *argv, char **envp);
char	*get_path(char **envp);
void	ft_error(void);

#endif