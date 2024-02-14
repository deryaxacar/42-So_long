/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:37:21 by beonturk          #+#    #+#             */
/*   Updated: 2023/10/30 23:37:22 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strstr;

	strstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !strstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		strstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strstr[i++] = s2[j++];
	}
	strstr[i] = '\0';
	return (strstr);
}
