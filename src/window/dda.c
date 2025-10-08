/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	5) DDA loop: step to next grid line in the smallest side_dist,
 	until we hit a wall	side = 0 for an x-side hit (vertical wall),
	side = 1 for a y-side hit (horizontal wall)
*/
void	dda(t_cub3d_data *data, int *side)
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
		if (is_wall(data, (double)data->player->map_x, \
(double)data->player->map_y))
			hit = 1;
	}
}

/*
** 6) Compute perpendicular wall distance (removes fish-eye distortion)
*/
void	fish_eye(t_cub3d_data *data, int *side)
{
	if (*side == 0)
		data->dda->perp_wall_dist = (data->player->map_x - data->player->x + \
(1 - data->dda->step_x) / 2.0) / data->dda->ray_dir_x;
	else
		data->dda->perp_wall_dist = (data->player->map_y - data->player->y + \
(1 - data->dda->step_y) / 2.0) / data->dda->ray_dir_y;
	if (data->dda->perp_wall_dist <= 0)
		data->dda->perp_wall_dist = 0.01;
}

/*
** 7) Project the wall height and compute the draw segment on screen
*/
void	project_wall(t_cub3d_data *data)
{
	data->dda->line_height = (int)(data->win_height / \
data->dda->perp_wall_dist);
	data->dda->draw_start = -data->dda->line_height / 2 + data->win_height / 2;
	data->dda->draw_end = data->dda->line_height / 2 + data->win_height / 2;
}
