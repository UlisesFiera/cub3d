/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/08 18:52:39 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}

static void	get_coord(t_player *player, char *dir, int *i, int *j)
{
	if (player->data->file_data->map[*i][*j] == 'N' || \
player->data->file_data->map[*i][*j] == 'S' || \
player->data->file_data->map[*i][*j] == 'W' || \
player->data->file_data->map[*i][*j] == 'E')
	{
		*dir = player->data->file_data->map[*i][*j];
		player->x = *j + 0.5;
		player->y = *i + 0.5;
		parse_dir(player, *dir);
	}
}

void	get_dir(t_player *player)
{
	int		i;
	int		j;
	char	dir;

	i = 0;
	while (player->data->file_data->map[i])
	{
		j = 0;
		while (player->data->file_data->map[i][j])
		{
			get_coord(player, &dir, &i, &j);
			j++;
		}
		i++;
	}
}
