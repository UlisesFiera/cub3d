/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 16:49:08 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map_data *map)
{
	if (map->map)
		free(map->map);
	map->map = NULL;
	if (map->map_fd != INULL)
		close(map->map_fd);
	map->map_fd = INULL;
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

void	free_mlx(t_cub3d_data *data)
{
	if (data->map_data)
	{
		free_map(data->map_data);
		free(data->map_data);
	}
	data->map_data = NULL;
	if (data->graph_data)
	{
		free_graph(data->graph_data);
		free(data->graph_data);
	}
	data->graph_data = NULL;
	if (data->win)
		mlx_destroy_window(data->mlx_id, data->win);
	data->win = NULL;
	if (data->mlx_id)
	{
		mlx_destroy_display(data->mlx_id);
		free(data->mlx_id);
	}
	data->mlx_id = NULL;
}
