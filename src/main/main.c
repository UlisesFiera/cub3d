/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:25:09 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/17 20:06:10 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(int argc, char **argv, t_mlx_data *mlx)
{
	ft_memset(mlx, 0, sizeof(t_mlx_data));
	mlx->map = smalloc(sizeof(t_map_data));
	mlx->graph = smalloc(sizeof(t_graphics));
	if (argc != 2)
		exiterr("Error: introduce 1 .ber map file as an argument", mlx, 1);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;

	init(argc, argv, &mlx);
	mlx.id = mlx_init();
	if (!mlx.id)
		exiterr("Error: mlx failed on init", &mlx, 201);
	window_manage(&mlx);
	mlx_loop(mlx.id);
	return (0);
}
