/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_column(t_cub3d_data *data, int x)
{
	int	side;

	ray_normalization(data, x);
	set_player_cell(data);
	set_cell_distance(data);
	set_cell_increment(data);
	dda(data, &side);
	fish_eye(data, &side);
	project_wall(data);
	if (side == 1)
		data->dda->wall_color = 0x777777;
	else
		data->dda->wall_color = 0xAAAAAA;
	draw_vertical(data, x, data->dda->wall_color);
}

int	render_loop(t_cub3d_data *data)
{
	int	x;

	update_player(data);
	draw_background(data);
	x = 0;
	while (x < data->win_width)
	{
		draw_column(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
	return (0);
}
