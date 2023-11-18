/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:24:19 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/18 16:11:01 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_ifzero(char *s)
{
	s = ft_calloc(2, sizeof(char));
	s[0] = '0';
	return (s);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*s;

	nb = n;
	len = ft_getlen(nb);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
		s = ft_ifzero(s);
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		s[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}
