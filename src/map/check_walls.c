/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:41:05 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 11:55:07 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int flood_fill(t_cub3d_data *data, char **map, int row, int col)
{
	if (row < 0 || col < 0
		|| row >= data->file_data->fill_map_height
		|| col >= data->file_data->fill_map_width)
		return (1);
	if (map[row][col] == '1' || map[row][col] == 'v')
		return (1);
	if (map[row][col] != '@')
	{
		openmaperr(map, row, col);
		return (0);
	}
	map[row][col] = 'v';
	if (!flood_fill(data, map, row - 1, col)
		|| !flood_fill(data, map, row + 1, col)
		|| !flood_fill(data, map, row, col - 1)
		|| !flood_fill(data, map, row, col + 1))
		return (0);
	return (1);
}

static	void copy_map_into_fill(char **map, char **fill_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == ' ')
				fill_map[i + 1][j + 1] = '@';
			else
				fill_map[i + 1][j + 1] = map[i][j];
			j++;
		}
		i++;
	}
}

static	char **fill_boundaries(t_cub3d_data *data, char **map)
{
	char	**fill_map;
	int		i;
	int		j;

	fill_map = smalloc(sizeof(char *) * (data->file_data->fill_map_height + 1));
	fill_map[data->file_data->fill_map_height] = NULL;
	i = 0;
	while (i < data->file_data->fill_map_height)
	{
		fill_map[i] = smalloc(data->file_data->fill_map_width + 1);
		fill_map[i][data->file_data->fill_map_width] = '\0';
		j = 0;
		while (j < data->file_data->fill_map_width)
			fill_map[i][j++] = '@';
		i++;
	}
	copy_map_into_fill(map, fill_map);
	return (fill_map);
}

void	check_walls(t_cub3d_data *data)
{
	char	**map;
	int		result;
	int		i;

	map_size(data);
	map = data->file_data->map;
	map = fill_boundaries(data, map);
	result = flood_fill(data, map, 0, 0);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	if (!result)
		exiterr("map must be surrounded by walls (1)", data, 301);
}

/*

We add a 0 at the corner of the new map to start the spreading from there

*/