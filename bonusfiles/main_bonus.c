/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:00 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:33:02 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

void	find_enemy_location(t_game *data)
{
	int	width;
	int	height;

	height = -1;
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			if (data->map[height][width] == 'N')
			{
				data->enemy_x = width;
				data->enemy_y = height;
			}
		}
	}
}

void	mlx_functions(t_game *data)
{
	mlx_hook(data->winpointer, 17, 0, (void *)exit, 0);
	data->counter = 0;
	mlx_hook(data->winpointer, 2, 0, &controls_working, data);
	data->enemy_speed = 0;
	mlx_loop_hook(data->mlxpointer, &enemy_move, data);
	mlx_loop(data->mlxpointer);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		map_control(argv[1], &data);
		map_reading(&data);
		map_processing(&data);
		wall_control(&data);
		data.mlxpointer = mlx_init();
		data.winpointer = mlx_new_window(data.mlxpointer,
				(data.map_width * RES), (data.map_height * RES), "so_long");
		images_in_game(&data);
		data.player = data.player_img;
		data.collectables = 0;
		map_bug(&data);
		find_enemy_location(&data);
		data.enemy = data.enemy_right;
		adding_graphics(&data);
		placeholder(&data, data.player_y, data.player_x);
		mlx_functions(&data);
	}
	else
		error_message("Error..!\nWrong Argument..!");
}
