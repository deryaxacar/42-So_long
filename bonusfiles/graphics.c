/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:32:52 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:32:53 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_player(t_game *data, int width, int height)
{
	data->player_x = width;
	data->player_y = height;
	mlx_put_image_to_window(data->mlxpointer, data->winpointer,
		data->player, data->player_x * RES, data->player_y * RES);
}

void	image_control(t_game *data)
{
	if (!data->player_img || !data->wall
		|| !data->exit || !data->collectable || !data->enemy_right
		|| !data->enemy_left || !data->close)
	{
		ft_printf("XPM file not found.!");
		exit_point(data);
	}
}

void	images_in_game(t_game *data)
{
	int	i;
	int	j;

	data->player_img = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/player.xpm", &i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/wall.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/exit.xpm", &i, &j);
	data->collectable = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/food.xpm", &i, &j);
	data->enemy_right = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/enemy.xpm", &i, &j);
	data->enemy_left = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/enemy.xpm", &i, &j);
	data->close = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/t_nathan.xpm", &i, &j);
	image_control(data);
}

void	adding_graphics(t_game *data)
{
	int	width;
	int	height;

	height = -1;
	mlx_clear_window(data->mlxpointer, data->winpointer);
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			if (data->map[height][width] == 'C')
				mlx_put_image_to_window(data->mlxpointer, data->winpointer,
					data->collectable, width * RES, height * RES);
			if (data->map[height][width] == 'E')
				mlx_put_image_to_window(data->mlxpointer, data->winpointer,
					data->exit, width * RES, height * RES);
			if (data->map[height][width] == '1')
				mlx_put_image_to_window(data->mlxpointer, data->winpointer,
					data->wall, width * RES, height * RES);
			if (data->map[height][width] == 'P')
				place_player(data, width, height);
		}
	}
}
