/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:41:39 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/16 15:44:27 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_checkinset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_checkinset(s1[end], set))
		end--;
	if (end < start)
	{
		s2 = malloc(1 * sizeof(char));
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	s2 = malloc(sizeof(char) * (end - start + 2));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[start], end - start + 2);
	return (s2);
}
