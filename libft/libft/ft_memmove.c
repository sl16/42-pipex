/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:13:39 by vbartos           #+#    #+#             */
/*   Updated: 2023/07/24 11:16:20 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char			*cdest;
	char			*csrc;

	if (!dest && !src)
	{
		return (dest);
	}
	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest > csrc)
	{
		while (n-- > 0)
		{
			cdest[n] = csrc[n];
		}
	}
	else
		ft_memcpy(cdest, csrc, n);
	return (dest);
}
