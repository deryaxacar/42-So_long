/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:33:34 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:33:35 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	move_control(t_game *data, int i, int j)
{
	if (data->map[i][j] == 'E')
	{
		if (data->collectables != 0)
			return (0);
		ft_printf("YOU WIN");
		exit_point(data);
	}
	if (data->map[i][j] == 'C')
	{
		data->collectables--;
	}
	if (data->map[i][j] == 'N')
	{
		ft_printf("YOU LOSE");
		exit_point(data);
	}
	data->map[i][j] = 'P';
	data->player_x = j;
	data->player_y = i;
	data->counter++;
	return (1);
}

static int	key_w_s(t_game *data, int movement)
{
	data->index.j = data->player_x;
	data->index.i = data->player_y;
	if (movement == 13)
	{
		if (data->map[--data->index.i][data->index.j] == '1')
			return (0);
		data->index.k = move_control(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i + 1][data->index.j] = '0';
	}
	else if (movement == 1)
	{
		if (data->map[++data->index.i][data->index.j] == '1')
			return (0);
		data->index.k = move_control(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i - 1][data->index.j] = '0';
	}
	return (1);
}

static int	key_a_d(t_game *data, int movement)
{
	data->index.j = data->player_x;
	data->index.i = data->player_y;
	if (movement == 0)
	{
		if (data->map[data->index.i][--data->index.j] == '1')
			return (0);
		data->index.k = move_control(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i][data->index.j + 1] = '0';
	}
	else if (movement == 2)
	{
		if (data->map[data->index.i][++data->index.j] == '1')
			return (0);
		data->index.k = move_control(data, data->index.i, data->index.j);
		if (!data->index.k)
			return (0);
		data->map[data->index.i][data->index.j - 1] = '0';
	}
	return (1);
}

int	controls_working(int key, t_game *data)
{
	if (key == ESC)
		exit_point(data);
	if (key == W)
		key_w_s(data, key);
	if (key == S)
		key_w_s(data, key);
	if (key == A)
		key_a_d(data, key);
	if (key == D)
		key_a_d(data, key);
	return (1);
}
