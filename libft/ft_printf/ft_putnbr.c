/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:35 by vbartos           #+#    #+#             */
/*   Updated: 2023/05/30 18:06:20 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		num = nbr * -1;
	}
	else
		num = nbr;
	if (num >= 10)
	{
		len += ft_putnbr(num / 10);
		len += ft_putnbr(num % 10);
	}
	else if (num < 10)
	{
		num = num + '0';
		len += ft_putchar(num);
	}
	return (len);
}
