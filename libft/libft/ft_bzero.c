/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:41:43 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/22 16:27:31 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, unsigned int n)
{
	unsigned int	i;
	unsigned char	*s;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (0);
}
