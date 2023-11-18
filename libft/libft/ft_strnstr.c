/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:36:55 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/03 15:01:33 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str_big;
	size_t	i;
	size_t	j;
	size_t	little_len;

	str_big = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (str_big);
	i = 0;
	j = 0;
	while (i < len && str_big[i] != '\0')
	{
		j = 0;
		while (str_big[i + j] == little[j]
			&& str_big[i + j] != '\0'
			&& little[j] != '\0'
			&& (i + j) < len)
			j++;
		if (j == little_len)
			return (str_big + i);
		i++;
	}
	return (NULL);
}
