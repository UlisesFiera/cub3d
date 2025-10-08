/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/10/08 18:27:50 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d_data	*data;

	data = NULL;
	if (argc != 2)
		exiterr("introduce 1 .cub map file as an argument", data, 1);
	data = smalloc(sizeof(t_cub3d_data));
	init_data(argv, data);
	window_manage(data);
	triggers(data);
	mlx_loop_hook(data->mlx_id, render_loop, data);
	mlx_loop(data->mlx_id);
	free_data(data);
	return (0);
}
