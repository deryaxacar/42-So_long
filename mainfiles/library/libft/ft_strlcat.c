/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:13 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 13:13:57 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	leng;
	size_t	counter;

	counter = 0;
	leng = ft_strlen(dst);
	if (size - 1 > leng && size > 0)
	{
		while (src[counter] != '\0' && size - 1 > leng + counter)
		{
			dst[counter + leng] = src[counter];
			counter++;
		}
		dst[leng + counter] = 0;
	}
	if (leng >= size)
		leng = size;
	return (leng + ft_strlen(src));
}
