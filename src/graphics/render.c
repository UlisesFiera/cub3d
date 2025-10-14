/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/13 18:27:38 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_column(t_cub3d_data *data, int x)
{
	int	side;

	ray_normalization(data, x);
	set_player_cell(data);
	set_ray_units_size(data);
	setup_ray_dir_and_start_pos(data);
	trace_ray(data, &side);
	fix_wall_dist_and_fish_eye(data, &side);
	assign_texture_to_sides(data, &side);
	col_setup(data);
	draw_slice(data, x);
	//mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
	//usleep(1000);
}

int	render_loop(t_cub3d_data *data)
{
	int	x;

	update_player(data);
	draw_background(data);
	x = 0;
	while (x < data->win_width)
		draw_column(data, x++);
	mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
	return (0);
}
