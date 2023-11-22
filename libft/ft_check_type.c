/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:41:09 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/09/29 15:34:30 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_print_char((char)va_arg(args, int));
	if (type == 's')
		count += ft_print_string((char *)va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_print_d_i((int)va_arg(args, int));
	if (type == 'p')
		count += ft_print_p(va_arg(args, void *));
	if (type == 'u')
		count += ft_print_unsigned((unsigned int)va_arg(args, unsigned int));
	if (type == 'X' || type == 'x')
		count += ft_set_x_type((int)va_arg(args, int), type);
	if (type == '%')
		count += ft_print_char('%');
	return (count);
}
