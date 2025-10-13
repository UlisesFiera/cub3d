/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:50:15 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/12 12:10:03 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*
	The vectors are the POV value.
*/