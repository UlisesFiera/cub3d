/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:55:30 by ulfernan          #+#    #+#             */
/*   Updated: 2025/09/20 18:45:25 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	graphic_init(t_cub3d_data *data)
{
	data->graph_data->x_size = 100;
	data->graph_data->y_size = 100;
}
