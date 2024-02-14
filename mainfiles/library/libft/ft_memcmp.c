/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:35:47 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:35:48 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *)s1)[c] != ((unsigned char *)s2)[c])
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
		c++;
	}
	return (0);
}
