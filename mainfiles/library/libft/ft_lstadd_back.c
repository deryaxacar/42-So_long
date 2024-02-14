/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:35:06 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:35:07 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*swap;

	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			swap = ft_lstlast(*lst);
			swap->next = new;
		}
	}
}
