/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:58:39 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/21 10:23:47 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_size(t_cub3d_data *data)
{
	char	*reader;
	int		new_column;

	data->map_data->map_height = 0;
	data->map_data->map_width = 0;
	reset_fd_cursor(data);
	while (1)
	{
		reader = get_next_line(data->map_data->map_fd);
		if (reader)
		{
			new_column = ft_strlen(reader);
			if (last_char(reader) == '\n')
				new_column--;
			if (new_column > data->map_data->map_width)
				data->map_data->map_width = new_column;
			data->map_data->map_height++;
			free(reader);
		}
		else
			break ;
	}
	if (data->map_data->map_height == 0 || data->map_data->map_width == 0)
		exiterr("error: couldn't read/empty map", data, 301);
}
