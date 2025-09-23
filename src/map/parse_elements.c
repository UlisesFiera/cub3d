/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:02:56 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/23 17:42:48 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_path(t_cub3d_data *data, char *line, t_element *element)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		exiterr("path to texture not provided", data, 301);
	element->path = line + i;
}

void	check_element(t_cub3d_data *data, char *line)
{
	int	none_found;
	int	i;

	none_found = 1;
	i = 0;
	while (data->map_data->elements[i] && none_found)
	{
		if (!data->map_data->elements[i]->found
			&& !ft_strncmp(line, data->map_data->elements[i]->name,
			ft_strlen(data->map_data->elements[i]->name)))
		{
			none_found = 0;
			data->map_data->elements[i]->found = 1;
			copy_path(data, line, data->map_data->elements[i]);
			data->map_data->elem_found++;
			if (data->map_data->elem_found == data->map_data->total_elem)
				return ;
		}
		i++;
	}
	if (none_found)
		dup_element(line, data);
}

void	parse_elements(t_cub3d_data *data)
{
	char	*line;
	int		i;

	reset_fd_cursor(data);
	line = get_next_line(data->map_data->file_fd);
	data->map_data->file_bread += ft_strlen(line);
	while (line && data->map_data->total_elem != data->map_data->elem_found)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] != '\n')
			check_element(data, line + i);
		free(line);
		line = get_next_line(data->map_data->file_fd);
		data->map_data->file_bread += ft_strlen(line);
	}
	parse_map(data, line);
}
