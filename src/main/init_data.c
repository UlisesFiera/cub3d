/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:11:55 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/08 18:43:31 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_resolution(t_cub3d_data *data)
{
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
}

void	init_data(char **argv, t_cub3d_data *data)
{
	data->mlx_id = NULL;
	data->win = NULL;
	data->img = NULL;
	data->file_data = smalloc(sizeof(t_file_data));
	data->graph_data = smalloc(sizeof(t_graphics));
	data->player = smalloc(sizeof(t_player));
	data->dda = smalloc(sizeof(t_dda));
	init_resolution(data);
	init_map(data, argv);
	init_graphic(data);
	init_player(data);
}
