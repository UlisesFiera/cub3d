/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/17 19:56:49 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	free_map(t_map_data *map)
{
	free(map->map);
	map->map = NULL;
	free(map->map_height);
	map->map_height = NULL;
	free(map->map_width);
	map->map_width = NULL;
}

void	free_graph(t_graphics *graph)
{
	free(graph->x_size);
	graph->x_size = NULL;
	free(graph->y_size);
	graph->y_size = NULL;
}

void	free_mlx(t_mlx_data *mlx)
{
	free(mlx->id);
	mlx->id = NULL;
	free(mlx->win);
	mlx->win = NULL;
	free_map(mlx->map);
	mlx->map = NULL;
	free_graph(mlx->graph);
	mlx->graph = NULL;
	free(mlx);
	mlx = NULL;
}
