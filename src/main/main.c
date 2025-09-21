/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/21 12:07:58 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(char **argv, t_cub3d_data *data)
{
	data->mlx_id = NULL;
	data->win = NULL;
	data->win_height = INULL;
	data->win_width = INULL;
	data->map_data = smalloc(sizeof(t_map_data));
	data->map_data->map = NULL;
	data->map_data->map_arg = NULL;
	data->map_data->map_fd = INULL;
	data->map_data->map_height = INULL;
	data->map_data->map_width = INULL;
	data->graph_data = smalloc(sizeof(t_graphics));
	data->graph_data->x_size = INULL;
	data->graph_data->y_size = INULL;
	init_data(data, argv);
	init_graphic(data);
}

int	main(int argc, char **argv)
{
	t_cub3d_data	*data;

	data = NULL;
	if (argc != 2)
		exiterr("error: introduce 1 .cub map file as an argument", data, 1);
	data = smalloc(sizeof(t_cub3d_data));
	init(argv, data);
	data->mlx_id = mlx_init();
	if (!data->mlx_id)
		exiterr("error: mlx failed on init", data, 201);
	window_manage(data);
	triggers(data);
	mlx_loop(data->mlx_id);
	free_mlx(data);
	free(data);
	return (0);
}
