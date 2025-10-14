/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:33:56 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 18:27:48 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_byte(t_cub3d_data *data, int *color)
{
	char 	*tex_color;
	int		index;

	index = data->dda->tex_y * data->dda->wall_texture->line_length \
				+ data->dda->tex_x \
				* (data->dda->wall_texture->bits_per_pixel / 8);
	tex_color = &data->dda->wall_texture->bytes[index];
	*color = (tex_color[2] << 16) | (tex_color[1] << 8) | tex_color[0];
}

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
void	draw_slice(t_cub3d_data *data, int x)
{
	int		wall_y;
	int		color;
	double	precise_tex_y;

	if (data->dda->draw_start < 0)
		data->dda->draw_start = 0;
	if (data->dda->draw_end >= data->win_height)
		data->dda->draw_end = data->win_height - 1;
	precise_tex_y = (data->dda->draw_start - data->win_height \
			/ 2 + data->dda->slice_height / 2) * data->dda->sampling;
	wall_y = data->dda->draw_start;
	while (wall_y <= data->dda->draw_end)
	{
		data->dda->tex_y = ((int)precise_tex_y * 2) % data->dda->wall_texture->height;
		if (data->dda->tex_y < 0)
			data->dda->tex_y = 0;
		if (data->dda->tex_y >= data->dda->wall_texture->height)
			data->dda->tex_y = data->dda->wall_texture->height - 1;
		get_texture_byte(data, &color);
		put_pixel(data, x, wall_y, color);
		precise_tex_y += data->dda->sampling;
		wall_y++;
	}
}
