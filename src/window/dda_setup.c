/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 1) Build the ray for this screen column from player dir + camera plane
**    camera_x maps screen x to [-1, 1], set in set_camera()
*/
void	ray_normalization(t_cub3d_data *data, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)data->win_width - 1.0;
	data->dda->ray_dir_x = data->player->dir_x + \
data->player->plane_vector_x * camera_x;
	data->dda->ray_dir_y = data->player->dir_y + \
data->player->plane_vector_y * camera_x;
}

/*
** 2) Starting cell in the map grid (integer coordinates of player position)
*/
void	set_player_cell(t_cub3d_data *data)
{
	data->player->map_x = (int)data->player->x;
	data->player->map_y = (int)data->player->y;
}

/*
** 3) Sets the scalar that expands vector directions for x and y
*/
void	set_cell_distance(t_cub3d_data *data)
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

/*
** 4) Determine step direction and initial
side distances to the first grid boundary
*/
void	set_cell_increment(t_cub3d_data *data)
{
	if (data->dda->ray_dir_x < 0)
	{
		data->dda->step_x = -1;
		data->dda->side_dist_x = (data->player->x - data->player->map_x) * \
data->dda->delta_dist_x;
	}
	else
	{
		data->dda->step_x = 1;
		data->dda->side_dist_x = (data->player->map_x + 1.0 - data->player->x) * \
data->dda->delta_dist_x;
	}
	if (data->dda->ray_dir_y < 0)
	{
		data->dda->step_y = -1;
		data->dda->side_dist_y = (data->player->y - data->player->map_y) * \
data->dda->delta_dist_y;
	}
	else
	{
		data->dda->step_y = 1;
		data->dda->side_dist_y = (data->player->map_y + 1.0 - data->player->y) * \
data->dda->delta_dist_y;
	}
}
