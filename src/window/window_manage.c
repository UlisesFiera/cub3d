/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:15:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/21 14:37:23 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub3d_data *data)
{
	printf("exiting cub3d...\n");
	free_mlx(data);
	free(data);
	exit(0);
}

void	window_manage(t_cub3d_data *data)
{
	data->win = mlx_new_window(
			data->mlx_id, data->win_width, data->win_height, "./cub3d");
	if (!data->win)
		exiterr("couldn't create new window", data, 201);
	return ;
}
