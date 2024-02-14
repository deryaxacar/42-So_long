/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:37:25 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:37:26 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	dlen;
	unsigned int	slen;

	if (size == 0)
		return (ft_strlen(src));
	x = ft_strlen(dst);
	i = 0;
	dlen = x;
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dst[x] = src[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (dlen + slen);
}
