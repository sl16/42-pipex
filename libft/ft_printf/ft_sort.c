/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:21:57 by vbartos           #+#    #+#             */
/*   Updated: 2023/06/01 10:20:45 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(va_list args, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		len = ft_putptr(va_arg(args, uintptr_t));
	else if (specifier == 'd' || specifier == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len = ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len = ft_hexadec(va_arg(args, unsigned int), specifier);
	else if (specifier == 'X')
		len = ft_hexadec(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
	{
		len = 1;
		ft_putchar('%');
	}
	return (len);
}
