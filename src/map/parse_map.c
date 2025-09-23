/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:30:37 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 18:39:34 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_nl(t_cub3d_data *data, char *line)
{
	int	i;
	
	while (line)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] == '\n')
		{
			free(line);
			line = get_next_line(data->map_data->file_fd);
			if (line)
				data->map_data->file_bread += ft_strlen(line);
		}
		else if (line[i] && line[i] != '\n')
		{
			free(line);
			return ;
		}
	}	
	exiterr("missing map info", data, 301);
}

void	map_alloc(t_cub3d_data *data)
{
	char	*line;
	int		size;
	int		i;

	size = 1;
	line = get_next_line(data->map_data->file_fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] == '\n')
		{
			free(line);
			exiterr("empty lines in map not allowed", data, 301);
		}
		size++;
		free(line);
		line = get_next_line(data->map_data->file_fd);
	}
	data->map_data->map = smalloc(sizeof (char *) * (size + 1));
	data->map_data->map[size] = NULL;
}

void	map_copy(t_cub3d_data *data)
{
	char	*line;
	int		bread;
	int		i;

	reset_fd_cursor(data);
	bread = 0;
	line = get_next_line(data->map_data->file_fd);
	if (line)
		bread += ft_strlen(line);
	while (bread < data->map_data->file_bread && line)
	{
		free(line);
		line = get_next_line(data->map_data->file_fd);
		if (line)
			bread += ft_strlen(line);
	}
	i = 0;
	while (line)
	{
		data->map_data->map[i] = ft_strdup(line); // need safe strdup
		i++;
		free(line);
		line = get_next_line(data->map_data->file_fd);
	}
}

void	parse_map(t_cub3d_data *data, char *line)
{
	skip_nl(data, line);
	map_alloc(data);
	map_copy(data);
}

// We start with size = 1 accounting for the line already found by skip_nl