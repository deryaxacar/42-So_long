/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:20 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:33:22 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ber_control(char *mapname)
{
	int	i;

	i = ft_strlen(mapname);
	if (mapname[i - 1] != 'r' || mapname[i - 2] != 'e'
		|| mapname[i - 3] != 'b' || mapname[i - 4] != '.')
		error_message("False .ber extension");
}

void	txt_control(char *mapname)
{
	int	fd;

	fd = open(mapname, O_RDONLY);
	if (fd < 0)
		error_message("Map not found");
	close(fd);
}

void	map_control(char *mapname, t_game *data)
{
	ber_control(mapname);
	data->maplocation = ft_strjoin("map/", mapname);
	txt_control(data->maplocation);
}
