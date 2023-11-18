/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:03:49 by vbartos           #+#    #+#             */
/*   Updated: 2023/06/01 10:44:55 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_gethexadeclen(unsigned int dec)
{
	int	len;

	len = 0;
	while (dec != 0)
	{
		dec = dec / 16;
		len++;
	}
	return (len);
}

char	*ft_hexadec_itoa(unsigned int dec, char specifier)
{
	int		len;
	char	*str;
	int		temp;

	len = ft_gethexadeclen(dec);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		temp = dec % 16;
		if (temp < 10)
			temp += 48;
		else
		{
			if (specifier == 'X')
				temp += 55;
			else
				temp += 87;
		}
		str[len--] = temp;
		dec = dec / 16;
	}
	return (str);
}

int	ft_hexadec(unsigned int dec, char specifier)
{
	char	*str;
	int		len;

	if (dec == 0)
	{
		ft_putchar('0');
		return (1);
	}
	str = ft_hexadec_itoa(dec, specifier);
	ft_putstr(str);
	len = ft_getlen(str);
	free(str);
	return (len);
}
