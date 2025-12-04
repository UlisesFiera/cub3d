/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:30:28 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 18:52:35 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_texture_to_sides(t_cub3d_data *data, int *side)
{
	if (*side == 0 && data->dda->step_x == 1)
	{
		data->dda->wall_color = 0x777777;
		data->dda->wall_texture = data->graph_data->ewall_texture;
		data->dda->side = 0;
	}
	else if (*side == 0 && data->dda->step_x == -1)
	{
		data->dda->wall_color = 0xFFFFFF;
		data->dda->wall_texture = data->graph_data->wwall_texture;
		data->dda->side = 1;
	}
	else if (*side == 1 && data->dda->step_y == 1)
	{
		data->dda->wall_color = 0xFF00FF;
		data->dda->wall_texture = data->graph_data->swall_texture;
		data->dda->side = 2;
	}
	else if (*side == 1 && data->dda->step_y == -1)
	{
		data->dda->wall_color = 0x0000FF;
		data->dda->wall_texture = data->graph_data->nwall_texture;
		data->dda->side = 3;
	}
}

static void	load_texture_data(t_cub3d_data *data, t_texture *texture, char obj)
{
	char	*texture_route;

	texture_route = NULL;
	if (obj == 'N')
		texture_route = data->graph_data->n_texture;
	else if (obj == 'S')
		texture_route = data->graph_data->s_texture;
	else if (obj == 'E')
		texture_route = data->graph_data->e_texture;
	else if (obj == 'W')
		texture_route = data->graph_data->w_texture;
	texture->img = mlx_xpm_file_to_image(data->mlx_id,
			texture_route, &texture->width, &texture->height);
	if (!texture->img)
		exiterr("error while loading texture", data, 401);
	texture->bytes = mlx_get_data_addr(
			texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}

void	load_textures(t_cub3d_data *data)
{
	load_texture_data(data, data->graph_data->nwall_texture, 'N');
	load_texture_data(data, data->graph_data->swall_texture, 'S');
	load_texture_data(data, data->graph_data->ewall_texture, 'E');
	load_texture_data(data, data->graph_data->wwall_texture, 'W');
}

/* 	
	Each texture is loaded as an array of bytes into 'texture->bytes',
	effectively storing a color in each, as well as the metadata in the
	rest of variables.
*/
