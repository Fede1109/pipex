/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:43:37 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 16:01:43 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_check_type(const char type, va_list args);
int	ft_print_char(char c);
int	ft_print_d_i(int nb);
int	ft_print_string(char *str);
int	ft_print_unsigned(unsigned int nb);
int	ft_set_x_type(unsigned int nb, int type);
int	ft_print_x(unsigned long nb, char *alpha);
int	ft_print_p(void *arg);

#endif