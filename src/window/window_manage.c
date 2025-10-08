/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:15:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:50:00 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub3d_data *data)
{
	printf("exiting cub3d...\n");
	free_data(data);
	free(data);
	exit(0);
}

void	window_manage(t_cub3d_data *data)
{
	data->mlx_id = mlx_init();
	if (!data->mlx_id)
	{
		exiterr("mlx failed on init", data, 201);
		return ;
	}
	data->win = mlx_new_window(
			data->mlx_id, data->win_width, data->win_height, NAME);
	if (!data->win)
	{
		exiterr("couldn't create new window", data, 201);
		return ;
	}
	data->img = mlx_new_image(data->mlx_id, data->win_width, data->win_height);
	data->metadata = mlx_get_data_addr(data->img, &data->bpp, \
&data->size_line, &data->endian);
	mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
}
