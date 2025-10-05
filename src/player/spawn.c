/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void parse_dir(t_player *player, char dir)
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

static	void get_coord(t_player *player, char *dir, int *i, int *j)
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

static	void get_dir(t_player *player)
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
	t_player	*player;

	player = smalloc(sizeof(t_player));
	player->key_up = false;
	player->key_left = false;
	player->key_down = false;
	player->key_right = false;
	player->angle = M_PI / 2;
	player->move_speed = 0.3; // units per frame (tune later)
	player->rot_speed = 0.2; // radians per frame (tune later)
	player->data = data;
	data->player = player;
	get_dir(player);
	/* With this we guarantee that the plane (camera vector) will always be perpendicular to the spawn direction
    otherwise, the image would flip, meaning that the right side of the screen would become the left side
	also the leght of this vector would affect the FOV. By this, the FOV would be 90 degrees, but multiplicating
	90 * 0.73 = 66 degrees we would get the FOV like the original Wolfenstein */
	player->plane_vector_x = -player->dir_y * 0.73;
	player->plane_vector_y = player->dir_x * 0.73;
}
