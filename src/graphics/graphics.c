/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cub3d_data *data, int x, int y, int color)
{
	int	index;

	if (x < 0 || y < 0 || x >= data->win_width || y >= data->win_height)
		return ;
	index = y * data->size_line + x * (data->bpp / 8);
	data->metadata[index] = color & 0xFF;
	data->metadata[index + 1] = (color >> 8) & 0xFF;
	data->metadata[index + 2] = (color >> 16) & 0xFF;
}

void	draw_vertical(t_cub3d_data *data, int x, int color)
{
	int	y;

	if (data->dda->draw_start < 0)
		data->dda->draw_start = 0;
	if (data->dda->draw_end >= data->win_height)
		data->dda->draw_end = data->win_height - 1;
	y = data->dda->draw_start;
	while (y <= data->dda->draw_end)
		put_pixel(data, x, y++, color);
}

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
