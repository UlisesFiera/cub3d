/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:19:10 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 18:35:36 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_tex_x(t_cub3d_data *data)
{
	double	wall_x;
	int		tex_x;

	if (data->dda->side == 0 || data->dda->side == 1)
		wall_x = data->player->y + data->dda->perp_wall_dist \
		* data->dda->ray_dir_y;
	else
		wall_x = data->player->x + data->dda->perp_wall_dist \
		* data->dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * data->dda->wall_texture->width * 2) \
	% data->dda->wall_texture->width;
	if (data->dda->side == 1 || data->dda->side == 3)
		tex_x = data->dda->wall_texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= data->dda->wall_texture->width)
		tex_x = data->dda->wall_texture->width - 1;
	return (tex_x);
}
