/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:35:51 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:35:52 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sc;
	size_t	i;

	dest = (char *)dst;
	sc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dest[i] = sc[i];
		i++;
	}
	return (dst);
}
