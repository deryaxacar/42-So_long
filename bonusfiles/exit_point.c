/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:32:41 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:32:47 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_images_free(t_game *data)
{
	if (data->player_img)
		mlx_destroy_image(data->mlxpointer, data->player_img);
	if (data->enemy_right)
		mlx_destroy_image(data->mlxpointer, data->enemy_right);
	if (data->enemy_left)
		mlx_destroy_image(data->mlxpointer, data->enemy_left);
	if (data->close)
		mlx_destroy_image(data->mlxpointer, data->close);
	if (data->collectable)
		mlx_destroy_image(data->mlxpointer, data->collectable);
	if (data->exit)
		mlx_destroy_image(data->mlxpointer, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlxpointer, data->wall);
	data->player = NULL;
	data->enemy = NULL;
}

int	exit_point(t_game *data)
{
	int	line;

	line = 0;
	if (data->winpointer)
		mlx_destroy_window(data->mlxpointer, data->winpointer);
	while (line < data->map_height)
		free(data->map[line++]);
	free(data->map);
	free(data->maplocation);
	mlx_images_free(data);
	exit(0);
}
