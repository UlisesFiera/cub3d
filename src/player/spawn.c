/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/08 18:48:41 by ulfernan         ###   ########.fr       */
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

static void	get_dir(t_player *player)
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

void	init_player(t_cub3d_data *data)
{
	data->player->key_up = false;
	data->player->key_left = false;
	data->player->key_down = false;
	data->player->key_right = false;
	data->player->angle = M_PI / 2;
	data->player->move_speed = 0.03;
	data->player->rot_speed = 0.02;
	data->player->data = data;
	get_dir(data->player);
	data->player->plane_vector_x = -data->player->dir_y * 0.73;
	data->player->plane_vector_y = data->player->dir_x * 0.73;
	data->player->rotate_right = false;
	data->player->rotate_left = false;
}
