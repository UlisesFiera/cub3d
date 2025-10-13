/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/12 11:34:13 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_cub3d_data *data)
{
	int	y;
	int	x;
	int	half_screen;

	y = 0;
	half_screen = data->win_height / 2;
	while (y < half_screen)
	{
		x = 0;
		while (x < data->win_width)
			put_pixel(data, x++, y, data->graph_data->c_color);
		y++;
	}
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
			put_pixel(data, x++, y, data->graph_data->f_color);
		y++;
	}
}
