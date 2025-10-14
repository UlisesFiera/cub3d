/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:26 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/14 06:15:38 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_graph(t_graphics *graph, t_cub3d_data *data)
{
	if (graph->nwall_texture)
	{
		if (graph->nwall_texture->img)
			mlx_destroy_image(data->mlx_id, graph->nwall_texture->img);
		graph->nwall_texture->img = NULL;
		free(graph->nwall_texture);
		graph->nwall_texture = NULL;
	}
	if (graph->swall_texture)
	{
		if (graph->swall_texture->img)
			mlx_destroy_image(data->mlx_id, graph->swall_texture->img);
		graph->swall_texture->img = NULL;
		free(graph->swall_texture);
		graph->swall_texture = NULL;
	}
	if (graph->ewall_texture)
	{
		if (graph->ewall_texture->img)
			mlx_destroy_image(data->mlx_id, graph->ewall_texture->img);
		graph->ewall_texture->img = NULL;
		free(graph->ewall_texture);
		graph->ewall_texture = NULL;
	}
	if (graph->wwall_texture)
	{
		if (graph->wwall_texture->img)
			mlx_destroy_image(data->mlx_id, graph->wwall_texture->img);
		graph->wwall_texture->img = NULL;
		free(graph->wwall_texture);
		graph->wwall_texture = NULL;
	}
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
