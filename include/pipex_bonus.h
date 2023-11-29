/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:19:06 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/29 17:25:42 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

void	child_process(char **argv, int *fd, char **envp);
void	parent_process(char **argv, int *fd, char **envp);
char	*get_cmd_route(char *path, char	*cmd);
void	execute_command(char *argv, char **envp);
char	*get_route(char **envp);
void	ft_error(void);

#endif