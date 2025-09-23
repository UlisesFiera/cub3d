/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 16:25:20 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(char **argv, t_cub3d_data *data)
{
	data->mlx_id = NULL;
	data->win = NULL;
	data->map_data = smalloc(sizeof(t_map_data));
	data->graph_data = smalloc(sizeof(t_graphics));
	init_data(data);
	init_map(data, argv);
	init_graphic(data);
}

int	main(int argc, char **argv)
{
	t_cub3d_data	*data;

	data = NULL;
	if (argc != 2)
		exiterr("introduce 1 .cub map file as an argument", data, 1);
	data = smalloc(sizeof(t_cub3d_data));
	init(argv, data);
	data->mlx_id = mlx_init();
	if (!data->mlx_id)
		exiterr("mlx failed on init", data, 201);
	window_manage(data);
	triggers(data);
	mlx_loop(data->mlx_id);
	free_mlx(data);
	free(data);
	return (0);
}
