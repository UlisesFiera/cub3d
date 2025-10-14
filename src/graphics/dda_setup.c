/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/14 18:53:49 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_normalization(t_cub3d_data *data, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)data->win_width - 1.0;
	data->dda->ray_dir_x = data->player->dir_x
		+ data->player->plane_vector_x * camera_x;
	data->dda->ray_dir_y = data->player->dir_y
		+ data->player->plane_vector_y * camera_x;
}

void	set_ray_units_size(t_cub3d_data *data)
{
	if (data->dda->ray_dir_x == 0)
		data->dda->delta_dist_x = INFINITY;
	else
		data->dda->delta_dist_x = fabs(1.0 / data->dda->ray_dir_x);
	if (data->dda->ray_dir_y == 0)
		data->dda->delta_dist_y = INFINITY;
	else
		data->dda->delta_dist_y = fabs(1.0 / data->dda->ray_dir_y);
}

void	setup_ray_dir_and_start_pos(t_cub3d_data *data)
{
	if (data->dda->ray_dir_x < 0)
	{
		data->dda->step_x = -1;
		data->dda->side_dist_x = (data->player->x - data->player->map_x)
			* data->dda->delta_dist_x;
	}
	else
	{
		data->dda->step_x = 1;
		data->dda->side_dist_x = (data->player->map_x + 1.0 - data->player->x)
			* data->dda->delta_dist_x;
	}
	if (data->dda->ray_dir_y < 0)
	{
		data->dda->step_y = -1;
		data->dda->side_dist_y = (data->player->y - data->player->map_y)
			* data->dda->delta_dist_y;
	}
	else
	{
		data->dda->step_y = 1;
		data->dda->side_dist_y = (data->player->map_y + 1.0 - data->player->y)
			* data->dda->delta_dist_y;
	}
}
