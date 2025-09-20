/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:07:08 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 17:25:45 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**alloc_map(t_cub3d_data *data)
{
	char	**map;
	char	*reader;
	int		count;

	count = 0;
	while (1)
	{
		reader = get_next_line(data->map_data->map_fd);
		if (reader)
			count++;
		else
			break ;
	}
	if (count == 0)
		return (NULL);
	map = smalloc(sizeof(char *) * count);
	return (map);
}

char	**process_map(t_cub3d_data *data, char **argv)
{
	char	**map;
	int		i;

	map = alloc_map(data);
	close(data->map_data->map_fd);
	data->map_data->map_fd = open(argv[1], O_RDONLY);
	if (data->map_data->map_fd == -1)
		exitperror(data, E_OPEN);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(data->map_data->map_fd);
		if (map[i])
			i++;
		else
			break ;
	}
	return (map);
}

void	parse_map(t_cub3d_data *data, char **argv)
{
	data->map_data->map_fd = open(argv[1], O_RDONLY);
	if (data->map_data->map_fd == -1)
		exitperror(data, E_OPEN);
	data->map_data->map = process_map(data, argv);
	if (!data->map_data->map)
		exiterr("error: couldn't read/empty map", data, 301);
}
