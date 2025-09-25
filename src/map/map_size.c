/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:58:39 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 10:51:59 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_size(t_cub3d_data *data)
{
	int	i;
	int	j;

	data->file_data->map_height = 0;
	data->file_data->map_width = 0;
	i = 0;
	while (data->file_data->map[i])
	{
		j = 0;
		while (data->file_data->map[i][j] && data->file_data->map[i][j] != '\n')
			j++;
		if (j > data->file_data->map_width)
			data->file_data->map_width = j;
		i++;
	}
	data->file_data->map_height = i;
	if (data->file_data->map_height <= 0 || data->file_data->map_width <= 0)
		exiterr("couldn't read/empty map", data, 301);
	data->file_data->fill_map_height = data->file_data->map_height + 2;
	data->file_data->fill_map_width = data->file_data->map_width + 2;
}
