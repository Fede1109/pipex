/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:33:27 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 16:48:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (ft_print_string("-2147483648"));
	else if (nb < 0)
	{
		count += ft_print_char('-');
		if (count < 0)
			return (-1);
		count += ft_print_d_i(-nb);
	}
	else if (nb > 9)
	{
		count += ft_print_d_i(nb / 10);
		if (count < 0)
			return (-1);
		count += ft_print_d_i(nb % 10);
	}
	else
		count += ft_print_char(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}
