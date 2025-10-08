/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_tabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:53:01 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 15:58:32 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*alloc_clean_line(t_cub3d_data *data, int row)
{
	char	*clean_line;
	int		size;
	int		j;

	size = 0;
	j = 0;
	while (data->file_data->map[row][j])
	{
		if (data->file_data->map[row][j] == '\t')
			size += 4;
		else
			size++;
		j++;
	}
	clean_line = malloc(size + 1);
	clean_line[size] = '\0';
	return (clean_line);
}

void	rm_tabs(t_cub3d_data *data, int row)
{
	char	*clean_line;
	int		i;
	int		j;

	clean_line = alloc_clean_line(data, row);
	i = 0;
	j = 0;
	while (data->file_data->map[row][j])
	{
		if (data->file_data->map[row][j] == '\t')
		{
			clean_line[i++] = ' ';
			clean_line[i++] = ' ';
			clean_line[i++] = ' ';
			clean_line[i++] = ' ';
		}
		else
			clean_line[i++] = data->file_data->map[row][j];
		j++;
	}
	free(data->file_data->map[row]);
	data->file_data->map[row] = clean_line;
}
