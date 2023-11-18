/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:58:34 by vbartos           #+#    #+#             */
/*   Updated: 2023/06/01 10:28:47 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		final_len;
	int		i;
	va_list	args;

	final_len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			final_len += ft_putchar(str[i]);
			i++;
		}
		else
		{
			final_len += ft_sort(args, str[i + 1]);
			i += 2;
		}
	}
	va_end(args);
	return (final_len);
}
