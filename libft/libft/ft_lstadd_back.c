/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:18:44 by vbartos           #+#    #+#             */
/*   Updated: 2023/02/22 16:47:54 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		if (*lst == NULL)
			ft_lstadd_front(lst, new);
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}
