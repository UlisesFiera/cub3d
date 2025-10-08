/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_cub3d_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= data->file_data->map_height)
		return (1);
	if (map_x < 0 || map_x >= data->file_data->map_width)
		return (1);
	return (data->file_data->map[map_y][map_x] == '1');
}
