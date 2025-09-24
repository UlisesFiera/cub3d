/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:48:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_graph(t_graphics *graph)
{
	(void)graph;
	return ;
}

void	free_data(t_cub3d_data *data)
{
	if (data->file_data)
	{
		free_file_data(data->file_data);
		free(data->file_data);
		data->file_data = NULL;
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
