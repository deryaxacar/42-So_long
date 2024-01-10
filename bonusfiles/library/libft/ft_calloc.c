/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:35:03 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:51:08 by deryacar         ###   ########.fr       */
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
