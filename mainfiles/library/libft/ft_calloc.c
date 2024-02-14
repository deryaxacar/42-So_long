/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:34:33 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:34:34 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pntr;

	pntr = malloc(size * count);
	if (!(pntr))
		return (NULL);
	ft_bzero(pntr, (count * size));
	return (pntr);
}
