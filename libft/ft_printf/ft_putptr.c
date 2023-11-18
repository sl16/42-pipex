/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:17:27 by vbartos           #+#    #+#             */
/*   Updated: 2023/06/01 10:20:22 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

char	*ft_hexadec_ptr_itoa(uintptr_t ptr)
{
	int		len;
	char	*str;
	int		temp;

	len = ft_getptrlen(ptr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		str[len--] = temp;
		ptr = ptr / 16;
	}
	return (str);
}

int	ft_putptr(uintptr_t ptr)
{
	char	*adress;
	int		len;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	adress = ft_hexadec_ptr_itoa(ptr);
	len = ft_putstr("0x") + ft_putstr(adress);
	free(adress);
	return (len);
}
