/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:32:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 16:00:37 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	v_args;

	va_start(v_args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_type(str[i], v_args);
		}
		else
			count += ft_print_char(str[i]);
		if (count < 0)
		{
			va_end(v_args);
			return (-1);
		}
		i++;
	}
	va_end(v_args);
	return (count);
}
