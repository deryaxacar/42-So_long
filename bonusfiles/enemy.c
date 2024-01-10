/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:32:17 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:32:19 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_screen(t_game *data)
{
	static int	i = 0;
	char		*line;
	int			x;
	int			y;

	x = 33;
	y = 33;
	line = ft_itoa(data->counter);
	mlx_string_put(data->mlxpointer, data->winpointer,
		x, y, 0x00FF00, "     Move Count : ");
	mlx_string_put(data->mlxpointer, data->winpointer,
		x + 120, y, 0x00FF00, line);
	free(line);
	if (++i <= 20)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->close, data->player_x * RES, data->player_y * RES);
	else if (++i <= 40)
		mlx_put_image_to_window(data->mlxpointer, data->winpointer,
			data->player, data->player_x * RES, data->player_y * RES);
	else
		i = 0;
}

void	put_enemy(t_game *data)
{
	mlx_put_image_to_window(data->mlxpointer, data->winpointer,
		data->enemy, data->enemy_x * RES, data->enemy_y * RES);
}

int	enemy_move(t_game *data)
{
	adding_graphics(data);
	game_screen(data);
	put_enemy(data);
	if (data->enemy_y == data->player_y
		&& data->enemy_x == data->player_x)
	{
		ft_printf("YOU LOSE");
		exit_point(data);
	}
	if (data->map[data->enemy_y][data->enemy_x] != 'E'
	&& data->map[data->enemy_y][data->enemy_x] != 'C')
		data->map[data->enemy_y][data->enemy_x] = '0';
	controls1(data);
	if (data->map[data->enemy_y][data->enemy_x] != 'E'
	&& data->map[data->enemy_y][data->enemy_x] != 'C')
		data->map[data->enemy_y][data->enemy_x] = 'N';
	return (1);
}
