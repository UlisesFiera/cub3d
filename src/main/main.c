/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 11:33:13 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(int argc, char **argv, t_mlx_data *mlx)
{
	mlx->id = NULL;
	mlx->win = NULL;
	mlx->map = smalloc(sizeof(t_map_data));
	mlx->map->map = NULL;
	mlx->map->map_height = NULL;
	mlx->map->map_width = NULL;
	mlx->graph = smalloc(sizeof(t_graphics));
	mlx->graph->x_size = NULL;
	mlx->graph->y_size = NULL;
	if (argc != 2)
		exiterr("Error: introduce 1 .ber map file as an argument", mlx, 1);
	mlx->map->map = argv;
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx;

	mlx = smalloc(sizeof(t_mlx_data));
	init(argc, argv, mlx);
	mlx->id = mlx_init();
	if (!mlx->id)
		exiterr("Error: mlx failed on init", mlx, 201);
	window_manage(mlx);
	mlx_loop(mlx->id);
	return (0);
}
