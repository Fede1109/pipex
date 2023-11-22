/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:34:34 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/14 12:53:30 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned long nb, char *alpha)
{
	int	count;	

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_x(nb / 16, alpha);
		if (count < 0)
			return (-1);
		count += ft_print_x(nb % 16, alpha);
	}
	else
		count += ft_print_char(alpha[nb]);
	return (count);
}
