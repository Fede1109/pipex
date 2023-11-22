/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:33:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 15:47:12 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	if (!str)
		return (ft_print_string("(null)"));
	while (str[count])
	{
		if (ft_print_char(str[count]) == -1)
			return (-1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}
