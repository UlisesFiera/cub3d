/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:02:46 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/24 10:50:15 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	triggers(t_cub3d_data *data)
{
    mlx_hook(data->win, 2, 1L << 0, key_press, data->player);
    mlx_hook(data->win, 3, 1L << 1, key_release, data->player);
    mlx_hook(data->win, 17, 0, close_window, data);
}
