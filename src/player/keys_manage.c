/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalguer <asalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:55:00 by asalguer          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:00 by asalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (keycode == W)
		player->key_up = true;
	else if (keycode == S)
		player->key_down = true;
	else if (keycode == D)
		player->key_left = true;
	else if (keycode == A)
		player->key_right = true;
	else if (keycode == LEFT)
		player->rotate_left = true;
	else if (keycode == RIGHT)
		player->rotate_right = true;
	else if (keycode == ESC)
	{
		printf("exiting cub3d...\n");
		free_data(player->data);
		free(player->data);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (keycode == W)
		player->key_up = false;
	else if (keycode == S)
		player->key_down = false;
	else if (keycode == D)
		player->key_left = false;
	else if (keycode == A)
		player->key_right = false;
	else if (keycode == LEFT)
		player->rotate_left = false;
	else if (keycode == RIGHT)
		player->rotate_right = false;
	return (0);
}
