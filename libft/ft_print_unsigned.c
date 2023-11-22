/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:34:08 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 16:49:55 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_print_d_i(nb / 10);
		if (count < 0)
			return (-1);
		count += ft_print_d_i(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
	{
		count += ft_print_char(nb + '0');
	}
	else
		return (-1);
	return (count);
}
