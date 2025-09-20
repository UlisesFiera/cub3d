/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 15:45:48 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map_data *map)
{
	if (map->map)
		free(map->map);
	map->map = NULL;
	if (map->map_height)
		free(map->map_height);
	map->map_height = NULL;
	if (map->map_width)
		free(map->map_width);
	map->map_width = NULL;
}

void	free_graph(t_graphics *graph)
{
	if (graph->x_size)
		free(graph->x_size);
	graph->x_size = NULL;
	if (graph->y_size)
		free(graph->y_size);
	graph->y_size = NULL;
}

void	free_mlx(t_mlx_data *mlx)
{
	if (mlx->map)
	{
		free_map(mlx->map);
		free(mlx->map);
	}
	mlx->map = NULL;
	if (mlx->graph)
	{
		free_graph(mlx->graph);
		free(mlx->graph);
	}
	mlx->graph = NULL;
	if (mlx->win)
		mlx_destroy_window(mlx->id, mlx->win);
	mlx->win = NULL;
	if (mlx->id)
	{
		mlx_destroy_display(mlx->id);
		free(mlx->id);
	}
	mlx->id = NULL;
}
