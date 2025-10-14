/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/13 18:20:06 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trace_ray(t_cub3d_data *data, int *side)
{
	int	hit;

	hit = 0;
	*side = 0;
	while (!hit)
	{
		if (data->dda->side_dist_x < data->dda->side_dist_y)
		{
			data->dda->side_dist_x += data->dda->delta_dist_x;
			data->player->map_x += data->dda->step_x;
			*side = 0;
		}
		else
		{
			data->dda->side_dist_y += data->dda->delta_dist_y;
			data->player->map_y += data->dda->step_y;
			*side = 1;
		}
		if (is_wall(data, (double)data->player->map_x,
			(double)data->player->map_y))
			hit = 1;
	}
}

void	fix_wall_dist_and_fish_eye(t_cub3d_data *data, int *side)
{
	if (*side == 0)
		data->dda->perp_wall_dist = (data->player->map_x \
		- data->player->x + (1 - data->dda->step_x) / 2.0) / data->dda->ray_dir_x;
	else
		data->dda->perp_wall_dist = (data->player->map_y \
		- data->player->y + (1 - data->dda->step_y) / 2.0) / data->dda->ray_dir_y;
	if (data->dda->perp_wall_dist <= 0)
		data->dda->perp_wall_dist = 0.01;
}

void	col_setup(t_cub3d_data *data)
{
	data->dda->slice_height = (int)(data->win_height / data->dda->perp_wall_dist);
	data->dda->draw_start = -data->dda->slice_height / 2 + data->win_height / 2;
	data->dda->draw_end = data->dda->slice_height / 2 + data->win_height / 2;
	data->dda->tex_x = get_tex_x(data);
	data->dda->sampling = (double)data->dda->wall_texture->height \
	/ data->dda->slice_height;
}

/*
	'side = 0' means we are facing the west or east side of a wall.
	'side = 1' means north or south.
*/