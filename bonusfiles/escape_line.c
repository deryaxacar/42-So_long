/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:32:29 by deryacar          #+#    #+#             */
/*   Updated: 2023/11/21 12:32:32 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	escape_line(t_game *data)
{
	data->index.i = -1;
	data->index.j = -1;
	data->index.e = 0;
	data->index.n = 0;
	data->index.p = 0;
}
