/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:57 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/18 14:24:04 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	found;

	i = 0;
	count = 0;
	found = 0;
	while (s && s[i])
	{
		if (found == 0 && s[i] != c)
		{
			found = 1;
			count++;
		}
		else if (s[i] == c)
			found = 0;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] != c && s[pos])
	{
		len++;
		pos++;
	}
	return (len);
}

static void	ft_freearr(char **arr, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static char	**ft_fillarr(char **arr, char const *s, char c, int count)
{
	int		arr_pos;
	int		pos;
	int		current_word_len;

	arr_pos = 0;
	pos = 0;
	while (arr_pos < count)
	{
		while (s[pos] == c)
			pos++;
		current_word_len = ft_wordlen(s, c, pos);
		arr[arr_pos] = ft_substr(s, pos, current_word_len);
		if (!arr[arr_pos])
		{
			ft_freearr(arr, arr_pos);
			return (NULL);
		}
		pos = pos + current_word_len;
		arr_pos++;
	}
	arr[arr_pos] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	count = ft_wordcount(s, c);
	arr = malloc(sizeof(char **) * (count + 1));
	if (!arr)
		return (NULL);
	return (ft_fillarr(arr, s, c, count));
}
