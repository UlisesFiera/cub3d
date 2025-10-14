/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 19:00:28 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_texture(t_texture *texture, t_cub3d_data *data)
{
	if (texture->img)
		mlx_destroy_image(data->mlx_id, texture->img);
	texture->img = NULL;
	free(texture);
	texture = NULL;
}

static void	free_graph(t_graphics *graph, t_cub3d_data *data)
{
	if (graph->nwall_texture)
		free_texture(graph->nwall_texture, data);
	if (graph->swall_texture)
		free_texture(graph->swall_texture, data);
	if (graph->ewall_texture)
		free_texture(graph->ewall_texture, data);
	if (graph->wwall_texture)
		free_texture(graph->wwall_texture, data);
	return ;
}

static void	free_mlx(t_cub3d_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx_id, data->img);
		data->img = NULL;
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
		free_graph(data->graph_data, data);
		free(data->graph_data);
		data->graph_data = NULL;
	}
	free_mlx(data);
	if (data->player)
		free(data->player);
	if (data->dda)
		free(data->dda);
	free(data);
}
