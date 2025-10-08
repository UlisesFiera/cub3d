/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:38:42 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:50:35 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_file_data2(t_file_data *file)
{
	int	i;

	if (file->elements)
	{
		i = 0;
		while (file->elements[i])
		{
			free(file->elements[i]);
			file->elements[i] = NULL;
			i++;
		}
		free(file->elements);
		file->elements = NULL;
	}
}

static void	free_file_data1(t_file_data *file)
{
	int	i;

	if (file->processed_file)
	{
		i = 0;
		while (file->processed_file[i])
			free(file->processed_file[i++]);
		free(file->processed_file);
		file->processed_file = NULL;
	}
	if (file->map)
	{
		i = 0;
		while (file->map[i])
			free(file->map[i++]);
		free(file->map);
		file->map = NULL;
	}
	if (file->file_fd != INULL)
	{
		close(file->file_fd);
		file->file_fd = INULL;
	}
}

void	free_file_data(t_file_data *file)
{
	free_file_data1(file);
	free_file_data2(file);
}
