/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:02:56 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 17:59:33 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void copy_path(t_cub3d_data *data, char *line, t_element *element)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		exiterr("path to texture or color not provided", data, 301);
	element->path = line + i;
	element->path[ft_strlen(element->path) - 1] = '\0';
}

static	void check_element(t_cub3d_data *data, char *line)
{
	int	none_found;
	int	i;

	none_found = 1;
	i = 0;
	while (data->file_data->elements[i] && none_found)
	{
		if (!data->file_data->elements[i]->found
			&& !ft_strncmp(line, data->file_data->elements[i]->name,
				ft_strlen(data->file_data->elements[i]->name)))
		{
			none_found = 0;
			data->file_data->elements[i]->found = 1;
			copy_path(data, line, data->file_data->elements[i]);
			data->file_data->elem_found++;
			if (data->file_data->elem_found == data->file_data->total_elem)
				return ;
		}
		i++;
	}
	if (none_found)
		dup_element(line, data);
}

void	parse_elements(t_cub3d_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file_data->processed_file[i]
		&& data->file_data->total_elem != data->file_data->elem_found)
	{
		j = 0;
		while (data->file_data->processed_file[i][j]
			&& data->file_data->processed_file[i][j] == ' ')
			j++;
		if (data->file_data->processed_file[i][j]
			&& data->file_data->processed_file[i][j] != '\n')
			check_element(data, data->file_data->processed_file[i] + j);
		i++;
	}
	parse_map(data, i);
}

// We put a '\0' at the end of the path to remove the new line at the end