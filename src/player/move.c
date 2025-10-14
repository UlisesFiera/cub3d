/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/13 18:13:03 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_cell(t_cub3d_data *data)
{
	data->player->map_x = (int)data->player->x;
	data->player->map_y = (int)data->player->y;
}

static void	calculate_dir(t_player *player, double *step_x, double *step_y)
{
	*step_x = 0.0;
	*step_y = 0.0;
	if (player->key_up)
	{
		*step_x += player->dir_x * player->move_speed;
		*step_y += player->dir_y * player->move_speed;
	}
	if (player->key_down)
	{
		*step_x -= player->dir_x * player->move_speed;
		*step_y -= player->dir_y * player->move_speed;
	}
	if (player->key_left)
	{
		*step_x += -player->dir_y * player->move_speed;
		*step_y += player->dir_x * player->move_speed;
	}
	if (player->key_right)
	{
		*step_x += player->dir_y * player->move_speed;
		*step_y += -player->dir_x * player->move_speed;
	}
}

static void	move_player(t_cub3d_data *data, t_player *player)
{
	double	step_x;
	double	step_y;
	double	new_x;
	double	new_y;

	calculate_dir(player, &step_x, &step_y);
	new_x = player->x + step_x;
	new_y = player->y + step_y;
	if (!is_wall(data, new_x, player->y))
		player->x = new_x;
	if (!is_wall(data, player->x, new_y))
		player->y = new_y;
}

void	update_player(t_cub3d_data *data)
{
	t_player	*player;

	player = data->player;
	rotate_player(player);
	move_player(data, player);
}
