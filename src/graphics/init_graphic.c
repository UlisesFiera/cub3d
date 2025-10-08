/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:55:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 18:45:12 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_element_paths(t_cub3d_data *data)
{
	int	i;

	i = 0;
	while (i < data->file_data->total_elem)
	{
		if (data->file_data->elements[i]->type == ELEM_NO)
			data->graph_data->n_texture = data->file_data->elements[i]->path;
		else if (data->file_data->elements[i]->type == ELEM_SO)
			data->graph_data->s_texture = data->file_data->elements[i]->path;
		else if (data->file_data->elements[i]->type == ELEM_EA)
			data->graph_data->e_texture = data->file_data->elements[i]->path;
		else if (data->file_data->elements[i]->type == ELEM_WE)
			data->graph_data->w_texture = data->file_data->elements[i]->path;
		else if (data->file_data->elements[i]->type == ELEM_F)
			data->graph_data->f_color = parse_color(
					data, data->file_data->elements[i]->path);
		else if (data->file_data->elements[i]->type == ELEM_C)
			data->graph_data->c_color = parse_color(
					data, data->file_data->elements[i]->path);
		i++;
	}
}

void	init_graphic(t_cub3d_data *data)
{
	data->graph_data->x_size = 100;
	data->graph_data->y_size = 100;
	set_element_paths(data);
}
