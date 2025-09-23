/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 18:38:34 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map_data *map)
{
	int	i;

	if (map->map)
	{
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		map->map = NULL;
	}
	if (map->file_fd != INULL)
	{
		close(map->file_fd);
		map->file_fd = INULL;
	}
	map->file_fd = INULL;
	if (map->elements)
	{
		i = 0;
		while (map->elements[i])
		{
			free(map->elements[i]);
			map->elements[i] = NULL;
			i++;
		}
		free(map->elements);
		map->elements = NULL;
	}
}

void	free_graph(t_graphics *graph)
{
	(void)graph;
	return ;
}

void	free_mlx(t_cub3d_data *data)
{
	if (data->map_data)
	{
		free_map(data->map_data);
		free(data->map_data);
		data->map_data = NULL;
	}
	if (data->graph_data)
	{
		free_graph(data->graph_data);
		free(data->graph_data);
		data->graph_data = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx_id, data->win);
		data->win = NULL;
	}
	if (data->mlx_id)
	{
		mlx_destroy_display(data->mlx_id);
		free(data->mlx_id);
		data->mlx_id = NULL;
	}
}
