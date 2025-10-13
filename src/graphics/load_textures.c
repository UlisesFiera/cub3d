/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:30:28 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/12 11:28:58 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture_data(t_cub3d_data *data, t_texture *texture, char obj)
{
	char	*texture_route;

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
