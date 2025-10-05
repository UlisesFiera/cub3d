/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:49:02 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/25 10:59:30 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void check_nl(t_cub3d_data *data)
{
	int	nl_found;
	int	i;
	int	j;

	nl_found = 0;
	i = 0;
	while (data->file_data->map[i])
	{
		j = 0;
		while (data->file_data->map[i][j] && data->file_data->map[i][j] == ' ')
			j++;
		if (data->file_data->map[i][j] && data->file_data->map[i][j] != '\n'
			&& nl_found)
			exiterr("empty lines between map lines not allowed", data, 301);
		if (data->file_data->map[i][j] && data->file_data->map[i][j] == '\n')
			nl_found = 1;
		i++;
	}
}

static	void check_chars(t_cub3d_data *data)
{
	char	reader;

	while (1)
	{
		reader = tab_reader(data->file_data->map, 0);
		if (reader == '\0')
			break ;
		if (reader != '0' && reader != '1' && reader != 'N' && reader != 'S'
			&& reader != 'W' && reader != 'E' && reader != '\n'
			&& reader != ' ' && reader != '\t')
			invalid_char(reader, data);
	}
}

static	void check_dup_chars(t_cub3d_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->file_data->map[i])
	{
		j = 0;
		while (data->file_data->map[i][j])
		{
			if (data->file_data->map[i][j] == 'N' || \
				data->file_data->map[i][j] == 'S' || \
				data->file_data->map[i][j] == 'W' || \
				data->file_data->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		no_dir_found(data);
	if (count > 1)
		dup_dir_element(data);
}

void	validate_file(t_cub3d_data *data)
{
	check_chars(data);
	check_dup_chars(data);
	check_nl(data);
	check_walls(data);
}
