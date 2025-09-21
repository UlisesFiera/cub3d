/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:02:46 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/21 11:26:56 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc(int keycode, t_cub3d_data *data)
{
	if (keycode == 65307)
	{
		printf("exiting cub3d...\n");
		free_mlx(data);
		free(data);
		exit(0);
	}
}

int	press(int keycode, t_cub3d_data *data)
{
	esc(keycode, data);
	return (0);
}

void	triggers(t_cub3d_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}
