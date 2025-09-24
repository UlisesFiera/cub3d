/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:30:37 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:52:40 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_nl(t_cub3d_data *data, int index)
{
	int	i;

	while (data->file_data->processed_file[index])
	{
		i = 0;
		while (data->file_data->processed_file[index][i]
			&& data->file_data->processed_file[index][i] == ' ')
			i++;
		if (data->file_data->processed_file[index][i]
			&& data->file_data->processed_file[index][i] == '\n')
			index++;
		else if (data->file_data->processed_file[index][i]
			&& data->file_data->processed_file[index][i] != '\n')
			return (index);
		index++;
	}
	exiterr("missing map content", data, 301);
	return (-1);
}

void	map_alloc(t_cub3d_data *data, int map_i)
{
	int		size;
	int		i;

	size = 1;
	while (data->file_data->processed_file[map_i])
	{
		size++;
		map_i++;
	}
	data->file_data->map = smalloc(sizeof (char *) * (size + 1));
	i = 0;
	while (i < size)
		data->file_data->map[i++] = NULL;
	data->file_data->map[size] = NULL;
}

void	map_copy(t_cub3d_data *data, int map_i)
{
	int		i;

	i = 0;
	while (data->file_data->processed_file[map_i])
	{
		data->file_data->map[i] = ft_strdup(
				data->file_data->processed_file[map_i]);
		if (!data->file_data->map[i])
			exiterr("fatal: malloc error in strdup", data, 101);
		i++;
		map_i++;
	}
}

void	parse_map(t_cub3d_data *data, int index)
{
	int	map_i;

	map_i = skip_nl(data, index);
	map_alloc(data, map_i);
	map_copy(data, map_i);
}

// We start with size = 1 accounting for the line already found by skip_nl
