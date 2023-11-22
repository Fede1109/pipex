/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:48:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 15:48:45 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *arg)
{
	int				count;
	char			*alpha;
	unsigned long	arg2;

	arg2 = (unsigned long)arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_print_string("0x");
	if (count != 2)
		return (-1);
	count += ft_print_x(arg2, alpha);
	return (count);
}
